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
	double getCoutMaintenance();
	int getProductivite();
	int getNombreEmployes();
	std::shared_ptr<Produit> getProduitType();
	std::vector<std::shared_ptr<Produit>> getStockProduitsFinis();

	// setters
	void setCoutMaintenance(double _coutMaintenance);
	void setProductivite(int _productivite);
	void setNombreEmployes(int _nombreEmployes);
	void setStockProduits(std::vector<std::shared_ptr<Produit>> _produits);
	void ajouterProduit(std::shared_ptr<Produit> produit);
	void setStockProduitFini(std::vector<std::shared_ptr<Produit>> _produits);
	void ajouterProduitFini(std::shared_ptr<Produit> produit);

	// ajouter une liste de produits au stock de fabrication
	void Usine::ajouterAuStock(std::vector<std::shared_ptr<Produit>> &produits);

	// recuperer produit de fabrication au stock
	std::shared_ptr<Produit> recupererProduitStockProd(int idProduit);

	// verifie si l'usine peut produit ce tour-ci
	bool Usine::peutProduire(std::vector<std::pair<std::shared_ptr<Produit>, int>> recette);

	// Produire des produits
	std::vector<std::shared_ptr<Produit>> produire(int salaireEmployes);

	// recuperer des produits
	std::vector<std::shared_ptr<Produit>> recupererProduits();

	std::vector<std::shared_ptr<Produit>> recupererProduits(int quantite);

	void afficherUsine();

protected:
	double coutMaintenance;
	int productivite;
	int nombreEmployes;
	std::vector<std::shared_ptr<Produit>> stockProduits;
	std::vector<std::shared_ptr<Produit>> stockProduitsFinis;
	std::shared_ptr<Produit> produitType;
};