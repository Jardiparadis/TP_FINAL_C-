#include <iostream>

#include "Entreprise.h"
#include "Produit.h"
#include "OrdreVente.h"

//Contructeur et Destructeur d'Ordre de Vente
OrdreVente::OrdreVente (std::shared_ptr<Entreprise> _ptrVendeur, std::shared_ptr<Produit> _ptrProduit, int _quantite, double _prix)
{
	ptrVendeur = _ptrVendeur;
	ptrProduit = _ptrProduit;
	quantite = _quantite;
	prix= _prix;
	std::cout << "Un Orde de Vente a ete emis.\n" << std::endl;
}


OrdreVente::~OrdreVente()
{
	std::cout << "Un Orde de Vente a ete revoque.\n" << std::endl;
}


//Setter et Getter de Vendeur
void OrdreVente::setVendeur(std::shared_ptr<Entreprise> _ptrVendeur)
{
	ptrVendeur = _ptrVendeur;
}

std::shared_ptr<Entreprise> OrdreVente::getVendeur()
{
	return ptrVendeur;
}


//Setter et Getter de Produit
void OrdreVente::setProduit(std::shared_ptr<Produit> _ptrProduit)
{
	ptrProduit = _ptrProduit;
}

std::shared_ptr<Produit> OrdreVente::OrdreVente::getProduit()
{
	return ptrProduit;
}


//Setter et Getter de Quantite mise en vente
void OrdreVente::setQuantite(int _quantite)
{
	quantite = _quantite;
}

int OrdreVente::getQuantite()
{
	return quantite;
}


//Setter et Getter de Prix
void OrdreVente::setPrix(double _prix)
{
	prix = _prix;
}

double OrdreVente::getPrix()
{
	return prix;
}