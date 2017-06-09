//compilar con gcc "gcc server.c -o server"
//ejecutar "./server"

#include <netinet/in.h>    
#include <stdio.h>    
#include <stdlib.h>    
#include <sys/socket.h>    
#include <sys/stat.h>    
#include <sys/types.h>    
#include <unistd.h>  
#include <string.h>  

    
int main() {  
// se crean los sockets  
   int create_socket, new_socket;    
   socklen_t addrlen;    
   int bufsize = 1;  
   char filecontador = '0';
   char *filename = "videoReporte.mjpeg";    //nombre del archivo a guardar
   char buffer = '0';       

 //se crea el socket que se encarga de escuchar
   if ((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0){printf("The socket was created\n");}
    
   struct sockaddr_in address;
   address.sin_family = AF_INET;    
   address.sin_addr.s_addr = INADDR_ANY;    
   address.sin_port = htons(9999);    
 
//se asocia el socket de escucha con el puerto
   if (bind(create_socket, (struct sockaddr *) &address, sizeof(address)) == 0){printf("Binding Socket\n");}
        
//se esperan llamadas
   while (1) 
	{  
      if (listen(create_socket, 10) < 0) {    
         perror("server: listen");    
         exit(1);    
      }    
    //se acceptan las llamadas entrantes y se manda a otro socket a atender la peticion
	addrlen = sizeof(struct sockaddr_in);
      if ((new_socket = accept(create_socket, (struct sockaddr *) &address, &addrlen)) < 0) {    
         perror("server: accept");    
         exit(1);    
      }    
    
      if (new_socket > 0){    
         printf("The Client is connected...\n");
      }
//se leen los parametros del cliente para ver que pide
      
	FILE *fptr;
	fptr = fopen(filename, "wb");

	int leido=0;
    while(read(new_socket, &buffer, 1)>0){  

	fputc( buffer, fptr );
	leido=leido+1;

}
	printf("%i\n",leido);  //cantidad de bytes recibidos

	fclose(fptr);

close(new_socket);

      
   }    
   close(create_socket);    
   return 0;    
}



