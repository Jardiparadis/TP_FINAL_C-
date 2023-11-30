#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#include "Produit.h"
#include "Usine.h"

#define coutTransitParKm 60
#define initialRDCost 10000;
#define nextRDLevelCost(level) (level * exp(level))

enum class EntrepriseType
{
	PRIMAIRE,
	SECONDAIRE
};


class Entreprise
{
public:

	// Ctor dtor
	Entreprise(const std::string& _nom, double _capital, double _salaireEmployes);
	~Entreprise();


	// Getter
	const std::string& getNom() const;
	double getCapital() const;
	const std::pair<int, int>& getCoordonnees() const;
	int getNiveauRD() const;
	const std::vector<std::shared_ptr<Usine>>& getUsines() const;
	double getSalaireEmployes() const;
	const std::map<int, double>& getStockVentes() const;
	const std::map<int, double>& getStockMatierePremiere() const;
	const std::map<int, double>& getGrillePrix() const;

	// Methods
	void creerUsine(double coutMaintenance, int productivite, int nombreEmployes, std::shared_ptr<Produit> produitType);
	double calculerCoutTransit(const std::shared_ptr<Entreprise> entreprise) const;

private:
	const std::string nom;
	double capital;
	std::pair<int, int> coordonnees;
	int niveauRD;
	std::vector<std::shared_ptr<Usine>> usines;
	double salaireEmployes;
	// Produit, quantité
	std::map<int, double> stockVentes;
	std::map<int, double> stockMatierePremiere;
	std::map<int, double> grillePrix;

	void ameliorerNiveauRD();
	void payerEmployees();
	void fonctionner();
	void acheterProduits();
};
