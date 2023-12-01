#pragma once

#include <iostream>

#include "Entreprise.h"
#include "Produit.h"

class OrdreVente
{
public:

	OrdreVente(std::shared_ptr<Entreprise> _ptrVendeur, std::shared_ptr<Produit> _ptrProduit, int _quantite, double _prix);
	~OrdreVente();
	std::shared_ptr<Entreprise> getVendeur() const;
	std::shared_ptr<Produit> getProduit() const;
	int getQuantite() const;
	double getPrix() const;
	void setVendeur(std::shared_ptr<Entreprise> _ptrVendeur);
	void setProduit(std::shared_ptr<Produit> _ptrProduit);	
	void setQuantite(int _quantite);
	void setPrix(double _prix);

private:
	std::shared_ptr<Entreprise> ptrVendeur;
	std::shared_ptr<Produit> ptrProduit;
	int quantite;
	double prix;
};