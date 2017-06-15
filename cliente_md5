//para compilar gcc cliente.c -o cliente
//para ejecutar ./cliente

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h> 
#include <stdlib.h> 

char *host, *filename;
int port, nThreads, nCycles;


//funcion para saber el largo de un archivo
int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}


//Main function
int main (int argc, char *argv[])
{
    host = "192.168.0.101";    //ip de la compu a la que se hay que conectar
    filename = "md5Checksum.txt";  //nombre de archivo a transferir

int r, s;
    struct sockaddr_in sin;
    char buf[1024];
    
    //Setup the socket 
    s = socket (AF_INET, SOCK_STREAM, 0);
    
    //Make the connection
    bzero (&sin, sizeof (sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons (6666);
    inet_aton (host, &sin.sin_addr);
    connect (s, (struct sockaddr *) &sin, sizeof (sin));
    

//se intenta abrir el archivo que quiere
	FILE *f = fopen(filename, "r");
//si el archivo no existe le envia una pagina de error
	if (f==NULL)
	{
	  printf("no existe el archivo\n");
	}
	else
	{
//si el archivo existe le envia el archivo
		
		int size = fsize(f);
		printf("%i\n",size); //cantidad de bytes a enviar
		char c; 
		 
		do
		{
		c = fgetc(f);
		if( feof(f) ){break ;}
		write(s, &c, 1);
		size=size-1;
		}while(size > 0);
	

		fclose(f);
		
	}
    

    close (s);
 
	
    return 0;
}




	

