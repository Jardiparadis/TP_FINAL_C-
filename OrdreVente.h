#pragma once

#include <iostream>

#include "Entreprise.h"
#include "Produit.h"

class OrdreVente
{
public:

	OrdreVente(std::shared_ptr<Entreprise> _ptrVendeur, std::shared_ptr<Produit> _ptrProduit, int _quantite, double _prix);

	~OrdreVente();


private:

	std::shared_ptr<Entreprise> ptrVendeur;
	std::shared_ptr<Produit> ptrProduit;
	int quantite;
	double prix;
};