#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main ()
{
   int ret;
   char str1[120] ;
   char string[120] ;

// Abrir el id unico
   FILE *f = fopen("id.txt", "r");

// Pasa el contenido del archivo a un string
   if(fgets(str1, 120, f)!=NULL)
   {
	fputs(str1, stdout) ;
	int index=0;
	while(str1[index]!='\n'){index=index+1;}
	str1[index]='\0';
        ret = rename("videoReporte.mp4", str1) ; // old, new
   }

   fclose(f) ;
   if(ret == 0){printf("File renamed successfully") ;}
   else{printf("Error: unable to rename the file") ;}
   return(0);
}
