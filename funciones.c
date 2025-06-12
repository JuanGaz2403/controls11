#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define NUM_PRODUCTOS 3
#define MAX_VENTAS 5

struct Producto productos[NUM_PRODUCTOS] = {
    {"Celular", 250}, 
    {"Microondas", 950},
    {"Laptop", 750.50}
};

int menu()
{
    int opc;
    printf("\n---Bienvenidos---\n");
    printf("1. Listar los productos\n");
    printf("2. Realizar una venta\n");
    printf("3. Ver todas las ventas (ver total de ventas)\n");
    printf("4. Buscar las ventas por cedula del cliente.\n");
    printf("5. Salir\n");
    scanf("%d", &opc);
    return opc;
}

void listarProductos(){
    printf("Productos Disponibles\n");
    for (int i = 0; i < NUM_PRODUCTOS; i++)
    {
        printf("%d. %s - %.2f\n", i+1, productos[i].nombre, productos[i].precio);
    }
    
}

void crearVenta(struct Venta ventas[], int *num_ventas ){
    if(*num_ventas >= MAX_VENTAS){
        printf("No se pueden realizar mas ventas. Limite alcanzado");
        return;
    }

    struct Venta nueva_venta;

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nueva_venta.nombreC);
    printf("Ingrese la cedula del cliente: ");
    scanf("%s", nueva_venta.cedula);

    printf("Ingrese la cantidad de productos (max 10)");
    scanf("%d", &nueva_venta.cantidad_productos);

    if(nueva_venta.cantidad_productos > MAX_VENTAS){
        printf("Cantidad de productos excede el limite permitido");
        return;
    }

    for (int i = 0; i < nueva_venta.cantidad_productos; i++)
    {
        printf("Seleccione el producto %d: \n", i+1);
        listarProductos();
        int opcion;
        scanf("%d", &opcion);
        nueva_venta.total_venta +=  nueva_venta.productos->precio;
        nueva_venta.productos[i] = productos[opcion-1];
    }
    printf("El total de su venta es: %f\n", nueva_venta.total_venta);
    ventas[*num_ventas] = nueva_venta;
    (*num_ventas)++;
    printf("Venta realizada\n");

}

void verVentas(struct Venta ventas[], int num_ventas){
    if (num_ventas == 0){
        printf("No hay ventas registradas.");
        return;
    }

    printf("Ventas regisradas:\n");
    for (int i = 0; i < num_ventas; i++){
        printf("Nombre: %s\n", ventas[i].nombreC);
        printf("Cedula: %s\n", ventas[i].cedula);
        printf("Productos:\n");
        for (int j = 0; j < ventas[i].cantidad_productos; j++)
        {
            printf("- %s - %f\n", ventas[i].productos->nombre, ventas[i].productos->precio );
        }
        printf("Total de la venta es: %f", ventas[i].total_venta);
        printf("\n");
    }
    
}

void buscarVenta(struct Venta ventas[], int num_ventas, const char *cedula){
    for (int i = 0; i < num_ventas; i++)
    {
        if (strcmp(ventas[i].cedula, cedula) == 0){
            printf("Nombre: %s\n", ventas[i].nombreC);
        printf("Cedula: %s\n", ventas[i].cedula);
        printf("Productos:\n");
        for (int j = 0; j < ventas[i].cantidad_productos; j++)
        {
            printf("- %s - %f\n", ventas[i].productos->nombre, ventas[i].productos->precio );
        }
        printf("Total de la venta es: %f", ventas[i].total_venta);
        printf("\n");
        return;
        }
        
    }
    printf("No se encontro una venta con la cedula: %s\n", cedula);
}

