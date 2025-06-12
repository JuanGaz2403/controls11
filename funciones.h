/*se desea desarrollar un sistema de gestion de ventas para una tienda de electrodomesticos y debera tener las siguientes funcionalidades
1. listar los productos
2. realizar una venta
3. ver todas las ventas (ver total de ventas)
4. buscar las ventas por cedula del cliente.

Una  venta tendra los siguientes atributos
1. nombre del cliente
2. cedula del cliente
3. cantidad de productos
4. total de la venta
5. productos vendidos (MAX 5 en una sola venta)

los atributos del producto
1. nombre
2. precio

el programa debe traer predefinido 3 productos
no se deben ingresar los productos*/

#include <stdio.h>
#include <string.h>
#define NUM_PRODUCTOS 3
struct Producto {
    char nombre[50];
    float precio;
};

struct Venta {
    char nombreC[50];
    char cedula[10];
    struct Producto productos[NUM_PRODUCTOS];
    int cantidad_productos;
    float total_venta;
};

int menu();
void listarProductos();
void crearVenta(struct Venta ventas[], int *num_ventas );
void verVentas(struct Venta ventas[], int num_ventas);
void buscarVenta(struct Venta ventas[], int num_ventas, const char *cedula);



