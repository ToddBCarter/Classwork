/*

client_assignment_3.c

Todd Carter
CS270
11-13-2023
cart7982@vandals.uidaho.edu

Client program that pairs with server_assignment_3.c.
The client inputs the string in the format of:

<operator><operand><operand>

as a single argument into the command line, and the answer
is calculated and returned by the server.

Valid operators are +, -, *, /, and %

*/

#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

//Random port chosen between 4500 and 4525
#define PORT 4509

int main(int argc, char* argv[])
{
   /*Variables for:
  	status - connection status for error message
      client_fd - connected socket to server
      received - data received back from server
      answer - converted answer
      */
   uint32_t status, client_fd, received, answer;

   char buffer[1024];

   //Setting the address of the server.
   struct sockaddr_in serv_addr;

   //Connect to the socket.
   if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   {
  	printf("\n Socket creation error \n");
  	return -1;
   }

   //Establish the address protocol and connection port.
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(PORT);

   //Convert IPv4 and IPv6 addresses from text to binary form.
   //Using inet_pton instead of bcopy since bcopy is deprecated.
   if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
   {
  	printf("\nInvalid address/ Address not supported.\n");
  	return -1;
   }

   //Establish the connection and error out if needed.
   if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
   {
  	printf("\nConnection failed.\n");
  	return -1;
   }

   //Sending the string taken from the command line.
   //send(client_fd, argv[1], strlen(argv[1]), 0);

   printf("Please enter the calculation.  Include spaces! \n");
   fgets(buffer,255,stdin);
   send(client_fd, buffer, strlen(buffer), 0);

   //Reading the response from the server.   
   read(client_fd, &received, sizeof(received));
   
   //Converting the received response into an integer.
   answer = ntohl(received);

   printf("Answer is: %d\n", answer);

   close(client_fd);
   return 0;
}
