#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Produit.h"

class Produit
{
public:

    Produit(int _id)
    {
        id = _id;
        coutDeBase = 0;
        coutDeProduction = 0;

        std::cout << " Un nouveau produit est disponible sur le marche." << std::endl;
    }

    ~Produit()
    {
        std::cout << " Le produit qui portait la reference " << id << " n'est plus sur le marche." << std::endl;
    }


    int getId()
    {
        return id;
    }

    /*
   void setId(int _id)
    {
        id = _id;
    }
*/

    void setcoutDeBase(double _coutDeBase)
    {
        coutDeBase = _coutDeBase;
    }


    double getcoutDeBase()
    {
        return coutDeBase;
    }


    void setCoutDeProduction(double _coutDeProduction)
    {
        if (_coutDeProduction < coutDeBase)
        {
            std::cout << "Attention, le cout de production du produit ne devrait inferieur a son cout de base!" << std::endl;
        }
        coutDeProduction = _coutDeProduction;
    }

    double getCoutDeProduction()
    {
        return coutDeProduction;
    }


protected:
    int id;
    double coutDeBase;
    double coutDeProduction;
};

