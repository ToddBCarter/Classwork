#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define SECTOR_SIZE 512
#define ROOT_DIR_ENTRIES 224
#define DIR_ENTRY_SIZE 32

typedef struct {
    uint8_t filename[11];
    uint8_t attributes;
    uint8_t reserved[10];
    uint16_t creation_time;
    uint16_t creation_date;
    uint16_t last_access_date;
    uint16_t ignored;
    uint16_t last_write_time;
    uint16_t last_write_date;
    uint16_t first_cluster;
    uint32_t file_size;
} __attribute__((packed)) DirectoryEntry;

int main(int argc, char *argv[]) {
    if (argc != 2) 
	{
        printf("Usage: %s <floppy_image>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) 
	{
        perror("open");
        return 1;
    }

    // Read the boot sector
    uint8_t boot_sector[SECTOR_SIZE];
    if (read(fd, boot_sector, SECTOR_SIZE) != SECTOR_SIZE) 
	{
        perror("read boot sector");
        close(fd);
        return 1;
    }
	
	printf("boot_sector is: %d\n", boot_sector);

    // Get the root directory location
    uint32_t root_dir_sector = *(uint16_t*)(boot_sector + 0x11);
    uint32_t fat_sector_count = *(uint16_t*)(boot_sector + 0x16);
    uint32_t fat_size_sectors = *(uint16_t*)(boot_sector + 0x16);
    uint32_t reserved_sector_count = *(uint16_t*)(boot_sector + 0x0E);
    uint32_t root_dir_offset = reserved_sector_count + fat_sector_count * fat_size_sectors;

    // Seek to the root directory
    if (lseek(fd, root_dir_offset * SECTOR_SIZE, SEEK_SET) == -1) 
	{
        perror("lseek root dir");
        close(fd);
        return 1;
    }

    // Read and print directory entries
    for (int i = 0; i < ROOT_DIR_ENTRIES; i++) {
        DirectoryEntry entry;
        if (read(fd, &entry, sizeof(DirectoryEntry)) != sizeof(DirectoryEntry)) 
		{
            perror("read directory entry");
            close(fd);
            return 1;
        }

        // Check if the entry is empty
        if (entry.filename[0] == 0x00 || entry.filename[0] == 0xE5) 
		{
            continue;
        }

        // Print file name
        printf("File: ");
        for (int j = 0; j < 11; j++) 
		{
            if (entry.filename[j] == ' ') 
			{
                break;
            }
        }
		//printf("Filename: %c\n", entry.filename[j]);
		//printf("Attributes: %c\n", entry.attributes);
		//printf("Creation Time: %c\n", entry.creation_time);
		//printf("Creation Date: %c\n", entry.creation_date);
        //printf("\n");

        // Print file size
        printf("Size: %u bytes\n", entry.file_size);
        printf("\n");
    }

    close(fd);
    return 0;
}
