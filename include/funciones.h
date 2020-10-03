#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stdio.h>

#include "../include/producto.h"

/**
 * Imprime una cadena de texto por la salida estandar.
 * 
 * @param texto Mensaje a imprimir en pantalla
 */
void imprimir(char* texto);

/**
 * Función que muestra los participantes del grupo
 */
void participantes();


/**
 * Función que verifica la existencia de un archivo
 */
bool existeArchivo(std::string);

/**
 * Crea el vector de productos con el primer CSV
 */
std::vector<Producto> generarProductos(std::string);


/**
 * Separar string por un delimitador
 */
std::vector<std::string> split(std::string, char);

/**
 * Crea las cantidades a partir del archivo de cantidades
 */
void generarCantidad(std::vector<Producto> &, std::string);



/**
 * Crea archivo Csv con resumen de productos y cantidades totales
 */
void generarCsv(std::vector<Producto>);


/**
 * Crear string a partir de un char.
 */
std::string getString(char);


#endif /* FUNCIONES_H */