#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Produit
{
public:

    Produit(int _id);
    ~Produit();
    int getId();
   //void setId(int _id);
    void setcoutDeBase(double _coutDeBase);
    double getcoutDeBase();
    void setCoutDeProduction(double _coutDeProduction);
    double getCoutDeProduction();
  
protected:
    int id;
    double coutDeBase;
    double coutDeProduction;
};
