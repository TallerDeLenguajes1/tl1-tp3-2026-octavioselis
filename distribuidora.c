#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};  

typedef struct { 
    int ProductoID;       //Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos       
    float PrecioUnitario; // entre 10 - 100 
}Producto;  

typedef struct {   
    int ClienteID;               // Numerado en el ciclo iterativo 
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
    Producto *Productos;   //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”                     
}Cliente;

float costoTotalProducto(Producto producto);
void mostrarTodo(Cliente *clientes,int cant);
int main(){
    int cantClientes = 5;
    Cliente *Clientes;

    srand(time(NULL));
    do{
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d",&cantClientes);
    }while(cantClientes > 5 || cantClientes <= 0);
    
    Clientes = (Cliente*)malloc(cantClientes*(sizeof(Cliente)));

    printf("\nCARGAR LOS DATOS DE LOS CLIENTES: \n");

    for(int i=0;i<cantClientes;i++){
        printf("\n--------------------------------\n");

        Clientes[i].ClienteID = i;

        printf("Ingrese el nombre del cliente:");

        char buff[50];
        fflush(stdin);
        gets(buff);

        int cantidadLetras = strlen(buff);
        Clientes[i].NombreCliente =(char*)malloc(cantidadLetras*(sizeof(char))+1);
        strcpy(Clientes[i].NombreCliente,buff);

        Clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        Clientes[i].Productos = (Producto*)malloc(Clientes[i].CantidadProductosAPedir*(sizeof(Producto)));

        for(int j=0;j<Clientes[i].CantidadProductosAPedir;j++){

            Clientes[i].Productos[j].ProductoID = j;
            Clientes[i].Productos[j].Cantidad = rand() % 10 + 1;

            int aux = rand() % 5;
            
            Clientes[i].Productos[j].TipoProducto = TiposProductos[aux];
            Clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
        }
    }

    mostrarTodo(Clientes,cantClientes);

    for(int i=0;i<cantClientes;i++){
        free(Clientes[i].Productos); 
    }
    free(Clientes);


return 0;
}



float costoTotalProducto(Producto producto){
    return producto.Cantidad * producto.PrecioUnitario;
}

void mostrarTodo(Cliente *clientes,int cant){
    for(int i=0;i<cant;i++){
        float totalPagar=0;
        printf("\n\n=========================================\n\n");
        printf("Nombre del cliente: %s\n",clientes[i].NombreCliente);
        printf("\nCantidad de productos a pedir de %s: %d\n", clientes[i].NombreCliente, clientes[i].CantidadProductosAPedir);
        printf("\n========= PRODUCTOS =========\n");

        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            totalPagar+= costoTotalProducto(clientes[i].Productos[j]);
            printf("- - - - - - - - - - - - - - - - - - - -\n");
            printf("%s:\n\n",clientes[i].Productos[j].TipoProducto);
            printf("Cantidad a llevar: %d\n",clientes[i].Productos[j].Cantidad);
            printf("Precio unitario: %f\n",clientes[i].Productos[j].PrecioUnitario);
        }
        printf("\n\n==============================\n\n");
        printf("TOTAL A PAGAR: %f", totalPagar);
        printf("\n\n==============================\n\n");
    }
}




/*

typedef struct {   
    int ClienteID;               // Numerado en el ciclo iterativo 
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
    Producto *Productos;   //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”                     
}Cliente;

typedef struct { 
    int ProductoID;       //Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos       
    float PrecioUnitario; // entre 10 - 100 
}Producto; 

*/