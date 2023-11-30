#include <iostream>

#include "Entreprise.h"
#include "Produit.h"
#include "OrdreVente.h"

OrdreVente::OrdreVente (std::shared_ptr<Entreprise> _ptrVendeur, std::shared_ptr<Produit> _ptrProduit, int _quantite, double _prix)
{
	std::shared_ptr<Entreprise> ptrVendeur = _ptrVendeur;
	std::shared_ptr<Produit> ptrProduit = _ptrProduit;
	int quantite = _quantite;
	double prix= _prix;
}

OrdreVente::~OrdreVente()
{

}