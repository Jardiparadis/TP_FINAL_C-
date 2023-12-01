#pragma once

#include "Produit.h"

// class Usine pour créer des produits
class Usine
{
public:

	// constructeur
	Usine(double _coutMaintenance, int _productivite, int _nombreEmployes, std::shared_ptr<Produit> _produitType);

	// destructeur
	~Usine();

	// getters

	// récupère le cout de maintenance
	double getCoutMaintenance();
	// récupère la productivité
	int getProductivite();
	// récupère le nombre d'employés
	int getNombreEmployes();
	// récupère le produit fabriqué par l'usine
	std::shared_ptr<Produit> getProduitType();
	// récupère un produit de fabrication du stock
	std::shared_ptr<Produit> recupererProduitStockProd(int idProduit);
	// récupère la liste des produits fabriqués par l'usine
	std::vector<std::shared_ptr<Produit>> getStockProduitsFinis();

	// setters
	// redéfini le cout de maintenance
	void setCoutMaintenance(double _coutMaintenance);
	// redéfini la productivité
	void setProductivite(int _productivite);
	// redéfini le noombre d'employés
	void setNombreEmployes(int _nombreEmployes);
	// redéfini le stock de produits de fabrication
	void setStockProduits(std::vector<std::shared_ptr<Produit>> _produits);
	// ajoute un produit de fabrication au stock
	void ajouterProduit(std::shared_ptr<Produit> produit);
	// redéfini le stock de produits fabriqués par l'usine
	void setStockProduitFini(std::vector<std::shared_ptr<Produit>> _produits);
	// ajoute un produit fabriqué par l'usine au stock
	void ajouterProduitFini(std::shared_ptr<Produit> produit);

	// ajouter une liste de produits de fabrication au stock
	void Usine::ajouterAuStock(std::vector<std::shared_ptr<Produit>> &produits);


	// verifie si l'usine peut produit ce tour-ci
	bool Usine::peutProduire(std::vector<std::pair<std::shared_ptr<Produit>, int>> recette);

	// Produire des produits
	std::vector<std::shared_ptr<Produit>> produire(int salaireEmployes);

	// recuperer des produits fabriqués par l'usine
	std::vector<std::shared_ptr<Produit>> recupererProduits();

	// recuperer des produits fabriqués par l'usine par quantité
	std::vector<std::shared_ptr<Produit>> recupererProduits(int quantite);

	// afficher les données d'une usine
	void afficherUsine();

protected:
	double coutMaintenance;
	int productivite;
	int nombreEmployes;

	// stock de produits necessaire pour faire un produit
	std::vector<std::shared_ptr<Produit>> stockProduits;

	// stock de produits fabriqués dans l'usine
	std::vector<std::shared_ptr<Produit>> stockProduitsFinis;

	// le produit que l'usine fabrique
	std::shared_ptr<Produit> produitType;
};