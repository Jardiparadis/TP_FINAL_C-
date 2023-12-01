#include "Entreprise.h"

Entreprise::Entreprise(const std::string &_nom, double _capital, double _salaireEmployes)
	: nom(_nom), capital(_capital), niveauRD(1), salaireEmployes(_salaireEmployes)
{
}

Entreprise::~Entreprise()
{
}

const std::string& Entreprise::getNom() const
{
	return nom;
}

double Entreprise::getCapital() const
{
	return capital;
}

const std::pair<int, int>& Entreprise::getCoordonnees() const
{
	return coordonnees;
}

int Entreprise::getNiveauRD() const
{
	return niveauRD;
}

const std::vector<std::shared_ptr<Usine>>& Entreprise::getUsines() const
{
	return usines;
}

double Entreprise::getSalaireEmployes() const
{
	return salaireEmployes;
}

const std::map<int, int>& Entreprise::getStockVentes() const
{
	return stockVentes;
}

const std::map<int, int>& Entreprise::getStockMatierePremiere() const
{
	return stockMatierePremiere;
}

const std::map<int, int>& Entreprise::getGrillePrix() const
{
	return grillePrix;
}

void acheterMatierePremiere(int quantite)
{
	//TO DO
	//apres ordre de vente
}


void Entreprise::ameliorerNiveauRD()
{
	double cost = nextRDLevelCost(niveauRD + 1);
	if (capital < cost)
	{
		std::cout << "Pas assez de capital pour investir en R&D" << std::endl;
		return;
	}
	capital -= cost;

	// Mettre à jour les usines
	for (const auto& usine : usines)
	{
		usine->setProductivite((usine->getProductivite() / niveauRD) * (niveauRD + 1));
		usine->setNombreEmployes((usine->getNombreEmployes() / niveauRD) * (niveauRD + 1));
	}

	niveauRD += 1;
}

void Entreprise::payerEmployees()
{
	for (const auto& usine : usines)
	{
		double coutUsine = usine->getNombreEmployes() * salaireEmployes;
		// Si l'entreprise n'a pas assez de capital pour payer les employés de l'usine, celle-ci se met en grêve
		if (capital < coutUsine)
		{
			usine->setProductivite(0);
			continue;
		}
		capital -= (usine->getNombreEmployes() * salaireEmployes);
	}
}

void Entreprise::fonctionner()
{
	// achat produits
	acheterProduits();

	// remplir les usines et les faire fonctionner
	std::cout << "L'entreprise tourne bien." << std::endl;
	for (std::shared_ptr<Usine> usine : usines)
	{
		std::vector<std::shared_ptr<Produit>> stockTemporaire;
		std::vector<std::pair<Produit*, int>> recette = usine->getProduitType()->getRecette();
		bool hasNotEnoughStock = false;
		auto itRecette = recette.begin();
		while (itRecette != recette.end())
		{
			Produit* prodToAdd = itRecette->first;
			int stockProduitRecette = stockMatierePremiere.at(prodToAdd->getId());
			if (stockProduitRecette == NULL)
			{
				hasNotEnoughStock = true;
				break;
			}
			if (stockProduitRecette < itRecette->second)
			{
				hasNotEnoughStock = true;
				break;
			}
			for (int i = 0; i < itRecette->second; i++)
			{
				stockTemporaire.push_back(std::make_shared<Produit>(prodToAdd->getId(), prodToAdd->getCoutDeBase(), 0, prodToAdd->getRecette()));
			}
			itRecette++;
		}
		if (hasNotEnoughStock)
		{
			std::cout << "Pas assez de produit achete pour fournir l'usine" << std::endl;
			usine->setProductivite(0);
		}

		usine->ajouterAuStock(stockTemporaire);
		usine->produire(salaireEmployes);
		std::vector<std::shared_ptr<Produit>> produitsFabriques = usine->recupererProduits();
		stockVentes.at(usine->getProduitType()->getId()) += produitsFabriques.size();
	}

	//vente des produits
	auto itProduitsVentes = stockVentes.begin();
	while (itProduitsVentes != stockVentes.end())
	{
		for (std::shared_ptr<Usine> usine : usines)
		{
			if (usine->getProduitType()->getId() == itProduitsVentes->first)
			{
				double prixProduit = usine->getProduitType()->getCoutDeProduction() * margeVente;
				std::shared_ptr<Marche> marche = Marche::getInstance();
				marche->creerOrdreDeVente(std::shared_ptr<Entreprise>(this), std::make_shared<Produit>(itProduitsVentes->first), itProduitsVentes->second, prixProduit);
			}
		}
	}

}

void Entreprise::acheterProduits()
{

}

void Entreprise::creerUsine(double coutMaintenance, int productivite, int nombreEmployes, Produit *produitType)
{
	std::shared_ptr<Usine> usine(new Usine(coutMaintenance, productivite, nombreEmployes, produitType));
	usines.push_back(usine);
}

double Entreprise::calculerCoutTransit(const std::shared_ptr<Entreprise> entreprise) const
{
	double distanceEntreEntreprises = sqrt(pow(coordonnees.first - entreprise->getCoordonnees().first, 2) + pow(coordonnees.second - entreprise->getCoordonnees().second, 2));
	return coutTransitParKm * distanceEntreEntreprises;
}

void Entreprise::setCapital(double _capital)
{
	capital = _capital;
}

void Entreprise::ajouterAuStockMatierePremiere(std::shared_ptr<Produit> produit, int quantite)
{
	stockMatierePremiere[produit->getId()] += quantite;
}

void Entreprise::retirerAuStockMatierePremiere(std::shared_ptr<Produit> produit, int quantite)
{
	stockMatierePremiere[produit->getId()] -= quantite;
}