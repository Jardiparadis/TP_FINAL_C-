#pragma once

#include <iostream>

#include "Produit.h"

class OrdreVente
{
public:

	OrdreVente(std::string _nomEntreprise, std::shared_ptr<Produit> _ptrProduit, int _quantite, double _prix);
	~OrdreVente();
	std::string getVendeur() const;
	std::shared_ptr<Produit> getProduit() const;
	int getQuantite() const;
	double getPrix() const;
	void setVendeur(std::string _ptrVendeur);
	void setProduit(std::shared_ptr<Produit> _ptrProduit);
	void setQuantite(int _quantite);
	void setPrix(double _prix);

private:
	std::string nomEntreprise;
	std::shared_ptr<Produit> ptrProduit;
	int quantite;
	double prix;
};