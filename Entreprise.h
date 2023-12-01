#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#include "Produit.h"
#include "Usine.h"

#define nextRDLevelCost(level) (level * exp(level))

constexpr int coutTransitParKm = 60;
constexpr double initialRDCost = 10000;

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
	const std::map<int, int>& getStockVentes() const;
	const std::map<int, int>& getStockMatierePremiere() const;
	const std::map<int, int>& getGrillePrix() const;
	void setCapital(double capital);
	void creerUsine(double coutMaintenance, int productivite, int nombreEmployes, Produit *produitType);
	double calculerCoutTransit(const std::shared_ptr<Entreprise> entreprise) const;
	void ajouterAuStockMatierePremiere(std::shared_ptr<Produit> produit, int quantite);
	void retirerAuStockMatierePremiere(std::shared_ptr<Produit> produit, int quantite);

private:
	const std::string nom;
	double capital;
	std::pair<int, int> coordonnees;
	int niveauRD;
	std::vector<std::shared_ptr<Usine>> usines;
	double salaireEmployes;
	// Produit, quantité
	std::map<int, int> stockVentes;
	std::map<int, int> stockMatierePremiere;
	std::map<int, int> grillePrix;

	void ameliorerNiveauRD();
	void payerEmployees();
	void fonctionner();
	void acheterProduits();
};
