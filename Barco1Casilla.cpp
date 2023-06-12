#include "Barco1Casilla.h"
#include <string>

Barco1Casilla::Barco1Casilla() : Barco(1) {}

Barco1Casilla::~Barco1Casilla() {}

std::string Barco1Casilla::getTipo() const {
  return "Barco de 1 casilla";
}
