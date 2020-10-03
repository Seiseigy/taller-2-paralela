#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <vector>

class Producto{
    private:
    public:
        long barCode;
        std::string name;
        int volume;
        int count;
        Producto(long, std::string, int);
        void addQuantity(int);
};




#endif // PRODUCTO_H