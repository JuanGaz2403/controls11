#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define NUM_PRODUCTOS 3
#define MAX_VENTAS 5

int main(){
    struct Venta ventas[MAX_VENTAS];
    int num_ventas = 0;
    int opc;
    
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            listarProductos();
            break;

        case 2:
            crearVenta(ventas, &num_ventas);
            break;

        case 3:
            verVentas(ventas, num_ventas);
            break;
        case 4:
            char cedula[10];
            printf("Ingrese la cedula para buscar la venta: ");
            scanf("%s", cedula);
            buscarVenta(ventas, num_ventas, cedula);
            break;

        default:
            break;
        }
    } while (opc != 5);
    return 0;
}
