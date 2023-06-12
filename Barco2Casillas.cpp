#include "Barco2Casillas.h"
#include <string>

Barco2Casillas::Barco2Casillas() : Barco(2) {}

Barco2Casillas::~Barco2Casillas() {}

std::string Barco2Casillas::getTipo() const {
  return "Barco de 2 casillas";
}
