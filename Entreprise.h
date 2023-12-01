#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#include "Produit.h"
#include "Usine.h"
#include "Marche.h"

#define nextRDLevelCost(level) (level * exp(level))

//Distinction entre les entreprises qui produissent  des matieres primaires (expl: bl�, charbon,..) ou secoudaire(pain, plastique, ..)
constexpr double margeVente = 1.35;
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
	const std::map<int, int>& getStockVentes() const;
	const std::map<int, int>& getStockMatierePremiere() const;
	const std::map<int, int>& getGrillePrix() const;
  
	// Methods
	void setCapital(double capital);
	void creerUsine(double coutMaintenance, int productivite, int nombreEmployes, std::shared_ptr<Produit> produitType);
	double calculerCoutTransit(const std::shared_ptr<Entreprise> entreprise) const;
	void afficherBilan();
	void ajouterAuStockMatierePremiere(std::shared_ptr<Produit> produit, int quantite);
	void retirerAuStockMatierePremiere(std::shared_ptr<Produit> produit, int quantite);
	void fonctionner();

private:
	const std::string nom;
	double capital;
	std::pair<int, int> coordonnees;
	int niveauRD;
	std::vector<std::shared_ptr<Usine>> usines;
	//Salaire universel dans l'entreprise
	double salaireEmployes;
	// Produit, quantité
	std::map<int, int> stockVentes;
	std::map<int, int> stockMatierePremiere;
	std::map<int, int> grillePrix;

	//Augmenter le niveau de R&D de l'entreprises si possible et augmenter la production
	void ameliorerNiveauRD();

	//Employes tous au meme salaire, si l'entreprise n'a pas assez de capital, la productivite tombe a 0
	void payerEmployees();

	//Permet a l'entreprise d'acheter de matieres premiers, de produire et de vendre sa production
	void fonctionner();
  
  //Permet d'acheter des produits
	void acheterProduits();
};
