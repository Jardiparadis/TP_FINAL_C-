#include "Marche.h"

Marche::~Marche()
{
	if (instanceMarche)
	{
		delete instanceMarche;
	}
}

Marche* Marche::getInstance()
{
	if (!instanceMarche)
	{
		instanceMarche = new Marche();
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

Marche::Marche()
{
}

Marche* Marche::instanceMarche = NULL;