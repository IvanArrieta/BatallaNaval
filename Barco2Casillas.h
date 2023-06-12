#ifndef BARCO2CASILLAS_H
#define BARCO2CASILLAS_H
#include "Barco.h"
#include <string>

class Barco2Casillas : public Barco {
public:
  Barco2Casillas();
  ~Barco2Casillas();

  std::string getTipo() const;
};

#endif
