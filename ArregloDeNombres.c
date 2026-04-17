#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *personas[],int cant);

int main(){

    char buff[50];
    char *nombres[5];
    for(int i=0;i<5;i++){
        printf("\nIngrese un nombre: ");

        gets(buff);
        int cantidadLetras = strlen(buff);

        nombres[i] =(char*)malloc(cantidadLetras*(sizeof(char))+1);
        strcpy(nombres[i],buff);
        
    }
    MostrarPersonas(nombres,5);

    for(int i=0;i<5;i++){
        free(nombres[i]);
    }

  
return 0;
}

void MostrarPersonas(char *personas[],int cant){
    for(int i=0;i<cant;i++){
        printf("%s\n",personas[i]);
    }
}  



