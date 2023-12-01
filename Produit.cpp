#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Produit.h"

Produit::Produit(int _id, int _coutDeBase, int _coutDeProduction, std::vector<std::pair<std::shared_ptr<Produit>, int>>& _recette)
    : id(_id), coutDeBase(_coutDeBase), coutDeProduction(_coutDeProduction), recette(_recette)
{
}

Produit::Produit(int _id)
{
    id = _id;
    coutDeBase = 0;
    coutDeProduction = 0;
    std::cout << " Un nouveau produit est disponible sur le marche." << std::endl;
}

Produit::~Produit()
{
    std::cout << " Le produit qui portait la reference " << id << " n'est plus sur le marche." << std::endl;
}


int Produit::getId()
{
    return id;
}

    /*
   void setId(int _id)
    {
        id = _id;
    }
*/

void Produit::setCoutDeBase(double _coutDeBase)
{
    coutDeBase = _coutDeBase;
}


double Produit::getCoutDeBase()
{
    return coutDeBase;
}

void Produit::setCoutDeProduction(double _coutDeProduction)
{
    if (_coutDeProduction < coutDeBase)
    {
        std::cout << "Attention, le cout de production du produit ne devrait inferieur a son cout de base!" << std::endl;
    }
    coutDeProduction = _coutDeProduction;
}

double Produit::getCoutDeProduction()
{
    return coutDeProduction;
}

double Produit::getCoutDeProductivite()
{
    return coutDeProductivite;
}

void Produit::setCoutDeProductivite(double _coutDeProductivite)
{
    coutDeProductivite = _coutDeProductivite;
}

std::vector<std::pair<std::shared_ptr<Produit>, int>> Produit::getRecette()
{
    return recette;
}