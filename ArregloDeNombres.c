#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void MostrarPersonas(char *personas[],int cant);
void BuscarNombre(char *nombres[],int id);
char * BuscarNombreClave(char *nombres[],int cant,char *clave);

int main(){
    srand(time(NULL));

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

    int buscado;
    printf("Busque un nombre mediante su ID: \n");
    scanf("%d",&buscado);
    BuscarNombre(nombres, buscado);

    char * nombre_con_clave= BuscarNombreClave(nombres,5,"jose");

    printf("Nombre buscado con clave: %s\n", nombre_con_clave);

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

void BuscarNombre(char *nombres[],int id){
    if(id>=5){
        printf("No se encontro el valor buscado\n");
    }
    else{   
        printf("-------- ID BUSCADO: %d --------\n",id);
        printf("%s\n",nombres[id]);
    }
}

char * BuscarNombreClave(char *nombres[],int cant,char *clave){
    for(int i=0;i<cant;i++){
        if(strstr(nombres[i],clave) !=NULL){
            return nombres[i];
        }
    }
    return "-1";
}