#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#define initialRDCost 10000;
#define nextRDLevelCost(level) (level * exp(level))

enum class EntrepriseType
{
	PRIMAIRE,
	SECONDAIRE
};

class Usine
{
public:
	int getNombreEmployes()
	{
		return 42;
	}
};
class Produit;

class Entreprise
{
public:
	// Ctor dtor
	Entreprise(const std::string &_nom, double _capital) : nom(_nom), capital(_capital), niveauRD(1)
	{
	}
	~Entreprise()
	{
	}
	// Getter
	const std::string& getNom() const
	{
		return nom;
	}
	double getCapital() const
	{
		return capital;
	}
	const std::pair<int, int>& getCoordonnees() const
	{
		return coordonnees;
	}
	int getNiveauRD()
	{
		return niveauRD;
	}
	const std::vector<std::shared_ptr<Usine>>& getUsines()
	{
		return usines;
	}
	double getSalaireEmployes()
	{
		return salaireEmployes;
	}
	const std::map<int, double>& getStockVentes()
	{
		return stockVentes;
	}
	const std::map<int, double>& getStockProduction()
	{
		return stockProduction;
	}
	const std::map<int, double>& getGrillePrix()
	{
		return grillePrix;
	}

	// Methods


private:
	const std::string nom;
	double capital;
	std::pair<int, int> coordonnees;
	int niveauRD;
	std::vector<std::shared_ptr<Usine>> usines;
	double salaireEmployes;
	// Produit, quantité
	std::map<int, double> stockVentes;
	std::map<int, double> stockProduction;
	std::map<int, double> grillePrix;



	void ameliorerNiveauRD()
	{
		double cost = nextRDLevelCost(niveauRD + 1);
		if (capital < cost)
		{
			return;
		}
		capital -= cost;
		niveauRD += 1;
	}

	void creerUsine()
	{
		// créer usine
	}

	void payerEmployees()
	{
		for (const auto& usine : usines)
		{
			capital -= (usine->getNombreEmployes() * salaireEmployes);
		}
	}

	void fonctionner()
	{
		std::cout << "L'entreprise tourne bien." << std::endl;
	}

	void acheterProduits()
	{

	}
};
