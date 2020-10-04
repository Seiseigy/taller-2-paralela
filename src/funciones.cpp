#include "../include/funciones.h"
#include <omp.h>
void imprimir(char* texto) {
    std::cout << texto << std::endl;
}

void participantes() {
    std::cout << std::endl << "=== Taller 2 ===" << std::endl;
    std::cout << std::endl << "Kevin Peralta"; 
    std::cout << std::endl << "Roberto Albornoz"; 
    std::cout << std::endl << "Sebastian Santelices" << std::endl; 
}

bool existeArchivo(std::string ruta)
{
  std::ifstream f(ruta.c_str());
  return f.good();
}

std::vector<std::string> split(std::string str, char delimitador) {



    std::vector<std::string> result;

    std::stringstream ss(str);


    while (ss.good()) {

        std::string substr;
        getline(ss, substr, delimitador);
        result.push_back(substr);
    }

    return result;

}


std::vector<Producto> generarProductos(std::string datos){

  std::vector<Producto> productos;

  std::ifstream file(datos);
  int saltoPrimera = 0;

  std::string line;
  while(getline(file, line)){
    if(saltoPrimera != 0){
      std::vector<std::string> arreglo = split(line, ';');
      long barCode_ = stol(arreglo[0].substr(1, arreglo[0].size()-2));
      std::string name_ = arreglo[1].substr(1, arreglo[1].size()-2);
      int volume_ = stoi(arreglo[2].substr(1, arreglo[2].size()-2));
      Producto producto(barCode_, name_, volume_);
      productos.push_back(producto);
    
    }else{
      saltoPrimera = saltoPrimera + 1;
    }

  }
  
  

  return productos;
  
}

void generarCantidad(std::vector<Producto> &productos, std::string datos){
#pragma omp parallel
  {
  int saltoPrimera = 0;
  std::ifstream file(datos);

  for(std::string line; getline(file, line);){
    if(saltoPrimera == 0){
      saltoPrimera = saltoPrimera + 1;
    }
    else{
      std::vector<std::string> arreglo = split(line, ';');
      long barCode_ = stol(arreglo[0].substr(1, arreglo[0].size()-2));
      int quantity_ = stoi(arreglo[1].substr(1, arreglo[1].size()-2));
      //std::cout << barCode_ << std::endl;
      //std::cout << quantity_ << std::endl;
#pragma omp for  
      for(unsigned int i = 0; i < productos.size(); i++){
        if(barCode_ == productos.at(i).barCode){
          productos.at(i).addQuantity(quantity_);
        }
      }   
    }
  }
  }
  
  
}

std::string getString(char x){
    std::string s(1,x);
    return s;
}

void generarCsv(std::vector<Producto> productos){
  std::string primera_linea = "\"barcode\";\"name\";\"volume\";\"count\"";
  std::ofstream myFile;
  //bool primera = 1;
  myFile.open("data/resumen.csv");
  
  myFile << primera_linea;
  myFile << std::endl;
#pragma omp parallel
  {

#pragma omp for  
  for(unsigned int i = 1; i < productos.size(); i++){
    /*
    if(primera == 1){
      myFile << primera_linea;
      myFile << std::endl;
      primera = 0;
    }
    */
    std::string barCode = "\""+std::to_string(productos.at(i).barCode)+"\";\"";
    std::string name = productos.at(i).name+"\";\"";
    std::string volume = std::to_string(productos.at(i).volume)+"\";\"";
    std::string count = std::to_string(productos.at(i).count)+"\"";
    std::string linea = barCode+name+volume+count;
    myFile << linea;
    myFile << std::endl;
  }
  std::cout << "Archivo creado con éxito" << std::endl;
  }
}

