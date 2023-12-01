#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Produit
{
public:
    Produit(int _id);
    Produit(int _id, int _coutDeBase, int _coutDeProduction, std::vector<std::pair<std::shared_ptr<Produit>, int>>& _recettes);
    ~Produit();
    int getId();
   //void setId(int _id);
    void setCoutDeBase(double _coutDeBase);
    double getCoutDeBase();
    void setCoutDeProduction(double _coutDeProduction);
    double getCoutDeProductivite();
    void setCoutDeProductivite(double _coutDeProduction);
    double getCoutDeProduction();
    std::vector<std::pair<std::shared_ptr<Produit>, int>> getRecette();
  
protected:
    int id;
    double coutDeBase;
    double coutDeProduction;
    double coutDeProductivite;
    // [ Produit, quantité ]
    std::vector<std::pair<std::shared_ptr<Produit>, int>> recette;
};
