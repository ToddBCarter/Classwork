/*

server_assignment_3.c

Todd Carter
CS270
11-13-2023
cart7982@vandals.uidaho.edu

Server program that pairs with client_assignment_3.c.
This server will receive a string from the client and perform the
given arithmetic according to prefix notation.

The client inputs the string in the format of:

<operator><operand><operand>

as a single argument into the command line.

*/

#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

//Random port chosen between 4500 and 4525.
#define PORT 4509

void removeSpaces(char* str)
{
   int count = 0;
   for (int i = 0; str[i]; i++)
   {
      if (str[i] == ' ')
      {
         str[i] = '@';
      }
      else
      {
         count++;
      }
   }
   str[count+1] = '\0';
}

int main(int argc, char const* argv[])
{
   /*Unsigned int variables are:
          server_fd - Server socket connection.
   	  socket_in - Input connection socket.
   	  answer - Calculated answer.
   	  answer_out - Converted answer sent to client.*/

   uint32_t server_fd, socket_in, answer, answer_out;

   //Establish server address.
   struct sockaddr_in address;
   socklen_t addrlen = sizeof(address);

   //Integer to set some parameters of the socket.
   int opt = 1;

   //Buffer array to receive data from client.
   char buffer[1024] = { 0 };

   //Establishing the socket with necessary parameters
   //and some error codes.
   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   {
  	perror("Socketing failed.");
  	exit(EXIT_FAILURE);
   }

   //Set socket options to allow reuse of the port and address.
   if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
   {
  	perror("Setsockopt failed.");
  	exit(EXIT_FAILURE);
   }

   //Set the protocol, server address, and port number.
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = INADDR_ANY;
   address.sin_port = htons(PORT);

   //Binding the socket to the port.
   if (bind(server_fd,(struct sockaddr*)&address, sizeof(address)) < 0)
   {
  	perror("Bind failed.");
  	exit(EXIT_FAILURE);
   }

   //Listening on the bound socket.
   if (listen(server_fd, 3) < 0)
   {
  	perror("Listen failed.");
  	exit(EXIT_FAILURE);
   }

   //Setting up the input socket.
   if ((socket_in = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0)
   {
  	perror("Accept failed.");
  	exit(EXIT_FAILURE);
   }

   //Use the input socket to load data into the buffer array.
   read(socket_in, buffer, sizeof(buffer) - 1);

   //removeSpaces(buffer);

   //Convert received string into usable data by removing null terminators.
   char sign = buffer[0];
   int oper1 = buffer[1] - '0';
   int oper2 = buffer[2] - '0';

   printf("buffer 0 is: %c\n", buffer[0]);
   printf("buffer 1 is: %c\n", buffer[1]);
   printf("buffer 2 is: %i\n", buffer[2]-'0');
   printf("buffer 3 is: %c\n", buffer[3]);
   printf("buffer 4 is: %i\n", buffer[4]-'0');

   sign = strtok(buffer, " ");
   oper1 = strtok(NULL, " ");
   oper2 = strtok(NULL, " ");

   printf("sign is: %c", sign);
   printf("oper1 is: %i", oper1);
   printf("oper2 is: %i", oper2);

   switch (sign)
   {
  	case '+':
     	answer = oper1 + oper2;
     	break;
        case '-':
		  answer = oper1 - oper2;
		  break;
        case '*':
		  answer = oper1 * oper2;
		  break;
        case '/':
		  answer = oper1 / oper2;
		  break;
  	case '%':
		  answer = oper1 % oper2;
		  break;
  	default:
		  printf("Unknown operator.\n");
		  return 1;
   }

   //Convert answer to be sent back to client.
   answer_out = htonl(answer);
   write(socket_in, &answer_out, sizeof(answer_out));

   close(socket_in);
   close(server_fd);

   return 0;
}


