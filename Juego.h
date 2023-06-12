#ifndef JUEGO_H
#define JUEGO_H
#include <string>
#include "Tablero.h"

class Juego {
private:
  Tablero tableroJugador1;
  Tablero tableroJugador2;
  bool turnoJugador1;

public:
  Juego();
  ~Juego();

  void iniciarJuego();
  void mostrarTableros() const;
  void jugarTurno();
  std::string obtenerCoordenadaDisparo() const;
};

#endif
