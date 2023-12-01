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

const std::map<int, double>& Entreprise::getStockVentes() const
{
	return stockVentes;
}

const std::map<int, double>& Entreprise::getStockMatierePremiere() const
{
	return stockMatierePremiere;
}

const std::map<int, double>& Entreprise::getGrillePrix() const
{
	return grillePrix;
}

void vendre(std::shared_ptr<Produit> produit, int quantite, double prix)
{
	//TO DO
}

void acheterMatierePremiere(int quantite)
{
	//TO DO
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
	std::cout << "L'entreprise tourne bien." << std::endl;
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