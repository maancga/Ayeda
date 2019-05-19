#pragma once
#include <iostream>
#include <fExplorar.hpp>
#include <fD_aleatoria.hpp>
#include <fD_modulo.hpp>
#include <fD_suma.hpp>

template <class CLAVE>
class fE_redisp : public fExplorar<CLAVE>
{
  private:
    int nCeldas;
    fDispersion<CLAVE> *hx;

  public:
    fE_redisp(int size, fDispersion<CLAVE> *funcion_h);
    ~fE_redisp();

    virtual int g(CLAVE clave, int i);
};

template <class CLAVE>
fE_redisp<CLAVE>::fE_redisp(int size, fDispersion<CLAVE> *funcion_h) : nCeldas(size), hx(funcion_h)
{
}

template <class CLAVE>
fE_redisp<CLAVE>::~fE_redisp()
{
}

template <class CLAVE>
int fE_redisp<CLAVE>::g(CLAVE clave, int i)
{
    int redisp = hx->h(clave);
    srand(clave);
    int funcion = (rand() % 3);
    switch (funcion)
    {
    case 0:
        return ((redisp + i) % nCeldas);
        break;
    case 1:
        return ((redisp + (i * i)) % nCeldas);
        break;
    case 2:
        return ((redisp + (i * redisp)) % nCeldas);
        break;
    default:
        std::cerr << "\nError en la función de redispersión. La exploración será lineal.\n";
        return ((redisp + i) % nCeldas);
        break;
    }
}
