#include "Marche.h"

Marche::Marche()
{
}

Marche::~Marche()
{
}

std::shared_ptr<Marche> Marche::getInstance()
{
	if (!instanceMarche)
	{
		instanceMarche = std::shared_ptr<Marche>(new Marche());
	}
	return instanceMarche;
}

void Marche::enregistrerEntreprise(const std::shared_ptr<Entreprise>& entreprise)
{
	entreprises.push_back(entreprise);
}	

void Marche::enregistrerProduit(const std::shared_ptr<Produit>& produit)
{
	produits.push_back(produit);
}

std::shared_ptr<Produit> Marche::getProduit(int idProduit)
{
	for (const std::shared_ptr<Produit>& produit : produits)
	{
		if (produit->getId() == idProduit)
		{
			return produit;
		}
	}
	return NULL;
}

std::shared_ptr<Marche> Marche::instanceMarche = NULL;
