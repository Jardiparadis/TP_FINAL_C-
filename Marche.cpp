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

void Marche::creerOrdreDeVente(std::string nomEntreprise, std::shared_ptr<Produit> produit, int quantity, double prix)
{
	ordresVente.push_back(OrdreVente(nomEntreprise, produit, quantity, prix));
}

std::shared_ptr<std::vector<OrdreVente>> Marche::chercherOrdreDeVentePourProduit(std::shared_ptr<Produit> produit)
{
	std::shared_ptr<std::vector<OrdreVente>> ordresSurProduit(new std::vector<OrdreVente>());

	for (const OrdreVente& ordreVente : ordresVente)
	{
		if (ordreVente.getProduit()->getId() == produit->getId())
		{
			ordresSurProduit->push_back(ordreVente);
		}
	}
	return ordresSurProduit;
}

void Marche::acheterOrdreDeVente(std::string nomEntrepriseAcheteuse, std::string nomEntrepriseVendeuse, std::shared_ptr<Produit> produit)
{
	int i = 0;
	for (const OrdreVente& ordreVente : ordresVente)
	{
		if (ordreVente.getProduit()->getId() == produit->getId() && ordreVente.getVendeur() == nomEntrepriseVendeuse)
		{
			/*entrepriseAcheteuse->setCapital(entrepriseAcheteuse->getCapital() - ordreVente.getPrix());
			entrepriseVendeuse->setCapital(entrepriseVendeuse->getCapital() + ordreVente.getPrix());
			entrepriseAcheteuse->ajouterAuStockMatierePremiere(produit, ordreVente.getQuantite());
			entrepriseVendeuse->retirerAuStockMatierePremiere(produit, ordreVente.getQuantite());
			*/
		}
		i += 1;
	}
}

std::shared_ptr<Marche> Marche::instanceMarche = NULL;
