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

const std::unordered_map<std::shared_ptr<Produit>, double>& Entreprise::getStockVentes()
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

void Entreprise::mettreStockEnVente()
{
	std::shared_ptr<Marche> marche = Marche::getInstance();
	for (const auto& produit : stockVentes)
	{
		std::shared_ptr<Produit> test = produit.first;
		std::shared_ptr<Entreprise> toto(this);
		marche->creerOrdreVente(toto, test, produit.second, 100.f);
	}
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
		return;
	}
	capital -= cost;
	niveauRD += 1;
}

void Entreprise::payerEmployees()
{
	for (const auto& usine : usines)
	{
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
