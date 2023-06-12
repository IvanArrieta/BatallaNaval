#include "Barco4Casillas.h"
#include <string>

Barco4Casillas::Barco4Casillas() : Barco(4) {}

Barco4Casillas::~Barco4Casillas() {}

std::string Barco4Casillas::getTipo() const {
  return "Barco de 4 casillas";
}
