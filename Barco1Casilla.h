#ifndef BARCO1CASILLA_H
#define BARCO1CASILLA_H
#include "Barco.h"
#include <string>

class Barco1Casilla : public Barco {
public:
  Barco1Casilla();
  ~Barco1Casilla();

  std::string getTipo() const;
};

#endif
