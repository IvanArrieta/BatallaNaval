#ifndef BARCO4CASILLAS_H
#define BARCO4CASILLAS_H
#include "Barco.h"
#include <string>

class Barco4Casillas : public Barco {
public:
  Barco4Casillas();
  ~Barco4Casillas();

  std::string getTipo() const;
};

#endif
