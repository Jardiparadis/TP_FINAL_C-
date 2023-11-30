#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#include "Produit.h"
#include "Usine.h"

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
	int getNiveauRD();
	const std::vector<std::shared_ptr<Usine>>& getUsines();
	double getSalaireEmployes();
	const std::map<int, double>& getStockVentes();
	const std::map<int, double>& getStockMatierePremiere();
	const std::map<int, double>& getGrillePrix();

	// Methods
	//std::vector<std::shared_ptr<Usine>> creerUsine(std::vector<std::shared_ptr<Usine>> ptrListeUsines);

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
