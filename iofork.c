#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int homi(char *archivo);

int main(int argc, char *argv[])
{
if (argc != 2) 
    {
      printf("Debes especificar una ruta de directorio.\n");
    }
  DIR *direct;
  struct dirent *cup;

  direct = opendir (argv[1]);

  if (direct == NULL){ 
    printf("No se puede abrir el directorio.\n");
	}

unsigned char clase;
int narch=0;
int total=0;

while ((cup = readdir (direct)) != NULL)
    {

	clase=cup->d_type;  
	if(clase==DT_REG){ 
		 FILE*f;

     	f=fopen(cup->d_name,"r");
  narch++;  
  	 }
closedir(direct);
direct=opendir(argv[1]);
 if (direct == NULL){ 
    printf("No se puede abrir el directorio.\n");
	}

int rec;
int a=0;
int b=0;
int arch=narch/2;
int pid = fork(); 
if (pid ==0){ 
a=0;
 b=narch;
}
else {
 a=narch;
 b=0;
}	

	
char *lista[1000000];


while ((cup = readdir (direct)) != NULL )
{
clase=cup->d_type;
 
if(clase==DT_REG){

FILE*f;  
f=fopen(cup->d_name,"r");
if((a || b)<0){
a=0;
b=0;
}
if(a<arch || b>arch){
  lista[narch]=(char *)malloc(sizeof(char) *strlen(cup->d_name)); 
strcat(lista[narch],argv[1]); 	
		strcat(lista[narch],"/");  	
		strcat(lista[narch],cup->d_name);
int reci=0;
			reci=homi(cup->d_name);
			total=total+reci;
}
  a--;
  b--;
   }
 	}
//closedir (direct);





}


/*
while ((cup = readdir (direct)) != NULL)
    {

	clase=cup->d_type;  
	if(clase==DT_REG){ 
		 FILE*f;

     	f=fopen(cup->d_name,"r");
     	lista[narch]=(char *)malloc(sizeof(char) *strlen(cup->d_name)); 
	 	strcat(lista[narch],argv[1]); 	
		strcat(lista[narch],"/");  	
		strcat(lista[narch],cup->d_name);
		int bytes=0;
	    bytes=homi(cup->d_name);
		total=total+bytes;
	    narch++;  
  	 }
 }*/
printf("Estudiante_1: 201622290\nEstudiante_2: 201627015\nTotal archivos: %d\nTotal bytes: %d\n",narch,total);

  closedir (direct);

  return EXIT_SUCCESS;

} 

int homi(char *name){
	FILE *fichero;

	fichero=fopen(name, "r"); 

	long chonta=0;
	
	do{  
     chonta++;  
    } while (fgetc(fichero)!=EOF);  

	return chonta;

}
