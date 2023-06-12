#include <iostream>
#include <string>
#include "Juego.h"
#include "Barco1Casilla.h"
#include "Barco2Casillas.h"
#include "Barco3Casillas.h"
#include "Barco4Casillas.h"


Juego::Juego() : tableroJugador1(9, 9), tableroJugador2(9, 9), turnoJugador1(true) {

}

Juego::~Juego() {

}
std::string Juego::obtenerCoordenadaDisparo() const {
  std::string coordenadaDisparo;
  std::cout << "Ingrese la coordenada para disparar: " << std::endl;
  std::cin >> coordenadaDisparo;
  return coordenadaDisparo;
}
void Juego::iniciarJuego() {
  std::cout << "¡Bienvenido a la Batalla Naval!" << std::endl;
  std::cout << "Jugador 1, coloca tus barcos." << std::endl;

  Barco4Casillas* barco4a = new Barco4Casillas();
  tableroJugador1.agregarBarco(barco4a, "A1", true);

  Barco3Casillas* barco3a = new Barco3Casillas();
  tableroJugador1.agregarBarco(barco3a, "A3", true);

  Barco3Casillas* barco3b = new Barco3Casillas();
  tableroJugador1.agregarBarco(barco3b, "A5", true);

  Barco2Casillas* barco2a = new Barco2Casillas();
  tableroJugador1.agregarBarco(barco2a, "A7", true);

  Barco2Casillas* barco2b = new Barco2Casillas();
  tableroJugador1.agregarBarco(barco2b, "A8", true);

  Barco1Casilla* barco1a = new Barco1Casilla();
  tableroJugador1.agregarBarco(barco1a, "D1", true);

  Barco1Casilla* barco1b = new Barco1Casilla();
  tableroJugador1.agregarBarco(barco1b, "D3", true);

  Barco1Casilla* barco1c = new Barco1Casilla();
  tableroJugador1.agregarBarco(barco1c, "D5", true);

  Barco4Casillas* barco4b = new Barco4Casillas();
  tableroJugador2.agregarBarco(barco4b, "G1", true);

  Barco3Casillas* barco3c = new Barco3Casillas();
  tableroJugador2.agregarBarco(barco3c, "G3", true);

  Barco3Casillas* barco3d = new Barco3Casillas();
  tableroJugador2.agregarBarco(barco3d, "G5", true);

  Barco2Casillas* barco2c = new Barco2Casillas();
  tableroJugador2.agregarBarco(barco2c, "G7", true);

  Barco2Casillas* barco2d = new Barco2Casillas();
  tableroJugador2.agregarBarco(barco2d, "G8", true);

  Barco1Casilla* barco1d = new Barco1Casilla();
  tableroJugador2.agregarBarco(barco1d, "E4", true);

  Barco1Casilla* barco1e = new Barco1Casilla();
  tableroJugador2.agregarBarco(barco1e, "F4", true);

  Barco1Casilla* barco1f = new Barco1Casilla();
  tableroJugador2.agregarBarco(barco1f, "H4", true);

  std::cout << "¡Comienza el juego!" << std::endl;

  while (true) {
    mostrarTableros();
    jugarTurno();
    if (tableroJugador1.flotaDestruida() || tableroJugador2.flotaDestruida()) {
      break;
    }
  }

  mostrarTableros();
  std::cout << "¡Fin del juego!" << std::endl;
  std::cout << "Jugador " << (tableroJugador1.flotaDestruida() ? "2" : "1") << " ha ganado." << std::endl;

  // Liberar la memoria de los barcos
  delete barco4a;
  delete barco3a;
  delete barco3b;
  delete barco2a;
  delete barco2b;
  delete barco1a;
  delete barco1b;
  delete barco1c;
  delete barco4b;
  delete barco3c;
  delete barco3d;
  delete barco2c;
  delete barco2d;
  delete barco1d;
  delete barco1e;
  delete barco1f;
}


void Juego::mostrarTableros() const {
  std::cout << "Tablero Jugador 1:" << std::endl;


  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (tableroJugador1.hayBarcoEnCoordenada(std::to_string(i + 1) + std::to_string(j + 1))) {
        std::cout << "X ";
      } else {
        std::cout << "- ";
      }
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  std::cout << "Tablero Jugador 2:" << std::endl;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (tableroJugador2.hayBarcoEnCoordenada(std::to_string(i + 1) + std::to_string(j + 1))) {
        std::cout << "X ";
      } else {
        std::cout << "- ";
      }
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Juego::jugarTurno() {
  std::string coordenadaDisparo;
  std::cout << "Turno del Jugador " << (turnoJugador1 ? "1" : "2") << std::endl;
  std::cout << "Ingrese la coordenada para disparar: " << std::endl;
  std::cin >> coordenadaDisparo;

  try {
    if (turnoJugador1) {
      if (tableroJugador2.dispararACoordenada(coordenadaDisparo)) {
        turnoJugador1 = true;
      } else {
        turnoJugador1 = false;
      }
    } else {
      if (tableroJugador1.dispararACoordenada(coordenadaDisparo)) {
        turnoJugador1 = false;
      } else {
        turnoJugador1 = true;
      }
    }
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

