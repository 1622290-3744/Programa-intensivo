int homi(char *name){
	FILE *fichero;

	fichero=fopen(name, "r"); 

	long chonta=0;
	
	do{  
     chonta++;  
    } while (fgetc(fichero)!=EOF);  

	return chonta;

}

int contador(char *argv[]){

        int narch=0;

        DIR *directorio;

	unsigned char tipo;

        struct dirent *dir;

        if(argc!=2){
                printf("Debes especificar una ruta de directorio.\n");
                return 1;
        }

        directorio=opendir(argv[1]);

        if (directorio == NULL){
                printf("No se puede abrir el directorio. \n");
                return 1;
        }

	while ((dir = readdir(directorio)) !=NULL){
				tipo=dir->d_type;
				if (tipo==DT_REG){		//CONTADOR DE ARCHIVOS
					narch++;
			}
        }
	printf("Total archivos:%i \n",narch);

	closedir(directorio);

        return 0;
}
