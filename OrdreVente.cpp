#include <iostream>

#include "Entreprise.h"
#include "Produit.h"
#include "OrdreVente.h"

//Contructeur et Destructeur d'Ordre de Vente
OrdreVente::OrdreVente (std::string _nomEntreprise, std::shared_ptr<Produit> _ptrProduit, int _quantite, double _prix)
{
	nomEntreprise = _nomEntreprise;
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
void OrdreVente::setVendeur(std::string _nomEntreprise)
{
	nomEntreprise = _nomEntreprise;
}

std::string OrdreVente::getVendeur() const
{
	return nomEntreprise;
}


//Setter et Getter de Produit
void OrdreVente::setProduit(std::shared_ptr<Produit> _ptrProduit)
{
	ptrProduit = _ptrProduit;
}

std::shared_ptr<Produit> OrdreVente::OrdreVente::getProduit() const
{
	return ptrProduit;
}


//Setter et Getter de Quantite mise en vente
void OrdreVente::setQuantite(int _quantite)
{
	quantite = _quantite;
}

int OrdreVente::getQuantite() const
{
	return quantite;
}


//Setter et Getter de Prix
void OrdreVente::setPrix(double _prix)
{
	prix = _prix;
}

double OrdreVente::getPrix() const
{
	return prix;
}