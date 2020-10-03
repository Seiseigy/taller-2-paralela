#include <iostream>
#include "include/funciones.h"
#include "include/producto.h"

#define rutaProductos "data/products_taller.csv"
#define rutaCantidades "data/trx_taller.csv"

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {
    
    std::vector<Producto> productos = generarProductos(rutaProductos);
    generarCantidad(productos, rutaCantidades);
    generarCsv(productos);

    participantes();
    return 0;
}

