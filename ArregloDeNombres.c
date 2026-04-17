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

    // --- INICIO DEL MENÚ DE BÚSQUEDA ---
    int opcion;
    int buscado;
    char clave_buscada[50];

    printf("\n--- MENU DE BUSQUEDA ---\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por Palabra Clave\n");
    printf("Elija una opcion (1 o 2): ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("\nIngrese el ID (indice del 0 al 4): ");
            scanf("%d", &buscado);
            BuscarNombre(nombres, buscado);
        break;

        case 2:
            printf("\nIngrese la palabra clave: ");
            scanf("%s", clave_buscada); 
            
            char *nombre_con_clave = BuscarNombreClave(nombres, 5, clave_buscada);
            
            if (strcmp(nombre_con_clave, "-1") == 0) {
                printf("No se encontro ningun nombre con esa palabra clave.\n");
            } else {
                printf("Nombre encontrado: %s\n", nombre_con_clave);
            }
        break;

        default:
            printf("\nOpcion no valida.\n");
        break;
    }
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