#ifndef TABLERO_H
#define TABLERO_H
#include <vector>
#include <string>
#include "Barco.h"

class Tablero {
private:
  int filas = 0;
  int columnas = 0;
  std::vector<std::vector<Barco*>> tablero;

public:
  Tablero(int filas, int columnas);
  ~Tablero();

  void agregarBarco(Barco* barco, const std::string& coordenadaInicial, bool esVertical);
  bool hayBarcoEnCoordenada(const std::string& coordenada) const;
  bool dispararACoordenada(const std::string& coordenada);
  bool flotaDestruida() const;
};

#endif

