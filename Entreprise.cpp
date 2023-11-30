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

int Entreprise::getNiveauRD()
{
	return niveauRD;
}

const std::vector<std::shared_ptr<Usine>>& Entreprise::getUsines()
{
	return usines;
}

double Entreprise::getSalaireEmployes()
{
	return salaireEmployes;
}

const std::map<int, double>& Entreprise::getStockVentes()
{
	return stockVentes;
}

const std::map<int, double>& Entreprise::getStockMatierePremiere()
{
	return stockMatierePremiere;
}

const std::map<int, double>& Entreprise::getGrillePrix()
{
	return grillePrix;
}

void Entreprise::ameliorerNiveauRD()
{
	double cost = nextRDLevelCost(niveauRD + 1);
	if (capital < cost)
	{
		return;
	}
	capital -= cost;
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

void Entreprise::creerUsine(double coutMaintenance, int productivite, int nombreEmployes, std::shared_ptr<Produit> produitType)
{
	std::shared_ptr<Usine> usine(new Usine(coutMaintenance, productivite, nombreEmployes, produitType));
	usines.push_back(usine);
}
