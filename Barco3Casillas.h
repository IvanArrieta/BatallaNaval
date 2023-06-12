#ifndef BARCO3CASILLAS_H
#define BARCO3CASILLAS_H
#include "Barco.h"
#include <string>

class Barco3Casillas : public Barco {
public:
  Barco3Casillas();
  ~Barco3Casillas();

  std::string getTipo() const;
};

#endif
