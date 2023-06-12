#ifndef BARCO_H
#define BARCO_H
#include <string>

class Barco {
protected:
  int longitud;
  int casillasGolpeadas;

public:
  Barco(int longitud);
  virtual ~Barco();

  int getLongitud() const;
  bool estaHundido() const;
  bool recibirDisparo();
  virtual std::string getTipo() const = 0;
};

#endif

