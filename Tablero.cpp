#include <iostream>
#include <string>
#include "Tablero.h"

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
  tablero.resize(filas, std::vector<Barco*>(columnas, nullptr));
}

Tablero::~Tablero() {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      delete tablero[i][j];
    }
  }
}

void Tablero::agregarBarco(Barco* barco, const std::string& coordenadaInicial, bool esVertical) {
  int fila = coordenadaInicial[0] - 'A';
  int columna = std::stoi(coordenadaInicial.substr(1)) - 1;

  if (esVertical) {
    for (int i = fila; i < fila + barco->getLongitud(); i++) {
      if (i >= filas || tablero[i][columna] != nullptr) {
        throw std::runtime_error("No se puede agregar el barco en esa ubicacion.");
      }
    }

    for (int i = fila; i < fila + barco->getLongitud(); i++) {
      tablero[i][columna] = barco;
    }
  } else {
    for (int j = columna; j < columna + barco->getLongitud(); j++) {
      if (j >= columnas || tablero[fila][j] != nullptr) {
        throw std::runtime_error("No se puede agregar el barco en esa ubicacion.");
      }
    }

    for (int j = columna; j < columna + barco->getLongitud(); j++) {
      tablero[fila][j] = barco;
    }
  }
}


bool Tablero::hayBarcoEnCoordenada(const std::string& coordenada) const {
  int fila = coordenada[0] - 'A';
  int columna = std::stoi(coordenada.substr(1)) - 1;

  return tablero[fila][columna] != nullptr;
}

bool Tablero::dispararACoordenada(const std::string& coordenada) {
  int fila = coordenada[0] - 'A';
  int columna = std::stoi(coordenada.substr(1)) - 1;

  if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
    if (tablero[fila][columna] != nullptr) {
      std::cout << "Barco impactado! Tipo de barco: " << tablero[fila][columna]->getTipo() << std::endl;
      if (tablero[fila][columna]->recibirDisparo()) {
        std::cout << "Barco hundido!" << std::endl;
      }
      tablero[fila][columna] = nullptr;
      return true;
    } else {
      std::cout << "Agua!" << std::endl;
    }
  } else {
    throw std::runtime_error("Coordenada invalida.");
  }

  return false;
}

bool Tablero::flotaDestruida() const {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (tablero[i][j] != nullptr) {
        return false;
      }
    }
  }

  return true;
}
