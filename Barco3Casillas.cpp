#include "Barco3Casillas.h"
#include <string>

Barco3Casillas::Barco3Casillas() : Barco(3) {}

Barco3Casillas::~Barco3Casillas() {}

std::string Barco3Casillas::getTipo() const {
  return "Barco de 3 casillas";
}
