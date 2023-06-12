#include "Barco.h"
#include <string>

Barco::Barco(int longitud) : longitud(longitud), casillasGolpeadas(0) {}

Barco::~Barco() {}

int Barco::getLongitud() const {
  return longitud;
}

bool Barco::estaHundido() const {
  return casillasGolpeadas >= longitud;
}

bool Barco::recibirDisparo() {
  casillasGolpeadas++;
  return estaHundido();
}
