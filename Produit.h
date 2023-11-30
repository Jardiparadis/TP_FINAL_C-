#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Produit
{
public:
    Produit(int _id);
    Produit(int _id, int _coutDeBase, int _coutDeProduction, std::vector<std::pair<Produit*, int>>& _recettes);
    ~Produit();
    int getId();
   //void setId(int _id);
    void setCoutDeBase(double _coutDeBase);
    double getCoutDeBase();
    void setCoutDeProduction(double _coutDeProduction);
    double getCoutDeProduction();
    std::vector<std::pair<Produit*, int>> getRecette();
  
protected:
    int id;
    double coutDeBase;
    double coutDeProduction;
    // [ Produit, quantité ]
    std::vector<std::pair<Produit*, int>> recette;
};
