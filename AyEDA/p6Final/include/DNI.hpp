#pragma once
#include <iostream>

class DNI
{
private:
  long int DNI_[8];

public:
  DNI();
  DNI(long int);

  operator int long() const;

  bool operator==(DNI) const;
  void operator=(DNI);
  bool operator<(DNI) const;
  // int operator[] (int);

  int get_dig(int i) const;

  friend std::ostream &operator<<(std::ostream &os, const DNI d);
};
