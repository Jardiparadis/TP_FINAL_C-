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

//Distinction entre les entreprises qui produissent  des matieres primaires (expl: blé, charbon,..) ou secoudaire(pain, plastique, ..)
enum class EntrepriseType
{
	PRIMAIRE,
	SECONDAIRE
};


class Entreprise
{
public:

	//Constructeur et destructeur d'Entreprise
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

	// Methodes
	void creerUsine(double coutMaintenance, int productivite, int nombreEmployes, Produit *produitType);
	double calculerCoutTransit(const std::shared_ptr<Entreprise> entreprise) const;

private:
	const std::string nom;
	double capital;
	std::pair<int, int> coordonnees;
	int niveauRD;
	std::vector<std::shared_ptr<Usine>> usines;
	//Salaire universel dans l'entreprise
	double salaireEmployes;
	// Produit, quantité
	std::map<int, double> stockVentes;
	std::map<int, double> stockMatierePremiere;
	std::map<int, double> grillePrix;

	//Augmenter le niveau de R&D de l'entreprises si possible et augmenter la production
	void ameliorerNiveauRD();

	//Employes tous au meme salaire, si l'entreprise n'a pas assez de capital, la productivite tombe a 0
	void payerEmployees();

	//Permet a l'entreprise d'acheter de matieres premiers, de produire et de vendre sa production
	void fonctionner();
	void acheterProduits();
};
