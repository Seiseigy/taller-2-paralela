#include "../include/producto.h"

Producto::Producto(long _barCode, std::string _name, int _volume){
    barCode = _barCode;
    name = _name;
    volume = _volume;
}

void Producto::addQuantity(int quantity){
    this->count = this->count + quantity;
}