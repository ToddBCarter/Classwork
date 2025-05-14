#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_SECTOR 512 // Assuming standard sector size for floppy disks
#define ROOT_DIR_ENTRIES 224 // Assuming standard number of root directory entries for floppy disks

// Function to locate the next cluster in the FAT
unsigned short getNextCluster(FILE *file, unsigned short cluster) {
    // Calculate the offset of the cluster entry in the FAT
    long offset = BYTES_PER_SECTOR + (3 * cluster) / 2;

    // Seek to the offset in the file
    fseek(file, offset, SEEK_SET);

    // Read the cluster entry (1.5 bytes)
    unsigned char bytes[2];
    fread(bytes, sizeof(unsigned char), 2, file);

    // Extract the relevant bits to determine the next cluster
    unsigned short nextCluster;
    if (cluster % 2 == 0) {
        nextCluster = ((bytes[1] & 0x0F) << 8) | bytes[0];
    } else {
        nextCluster = (bytes[1] << 4) | ((bytes[0] & 0xF0) >> 4);
    }

    return nextCluster;
}

// Function to read data from a cluster
void readDataFromCluster(FILE *file, unsigned short cluster) {
    // Calculate the offset of the cluster data in the file
    long offset = BYTES_PER_SECTOR + (ROOT_DIR_ENTRIES + cluster - 2) * BYTES_PER_SECTOR; // Assuming cluster size of one sector

    // Seek to the offset in the file
    fseek(file, offset, SEEK_SET);

    // Read and print the data from the cluster
    unsigned char buffer[BYTES_PER_SECTOR];
    fread(buffer, sizeof(unsigned char), BYTES_PER_SECTOR, file);
    printf("Data from cluster %d:\n", cluster);
    for (int i = 0; i < BYTES_PER_SECTOR; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if the file name is provided as a command-line argument
    if (argc != 2) {
        printf("Usage: %s <disk_image_file>\n", argv[0]);
        return 1;
    }

    // Open the disk image file for reading
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Example: Get next cluster for cluster 5
    unsigned short currentCluster = 5;
    unsigned short nextCluster = currentCluster;
    while (nextCluster < 0xFF8) { // End of cluster chain marker in FAT12
        // Read data from the current cluster
        readDataFromCluster(file, nextCluster);

        // Get the next cluster
        nextCluster = getNextCluster(file, nextCluster);
    }

    // Close the file
    fclose(file);

    return 0;
}
