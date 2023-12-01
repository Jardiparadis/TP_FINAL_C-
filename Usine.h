#pragma once

#include "Produit.h"

// class Usine pour cr�er des produits
class Usine
{
public:

	// constructeur
	Usine(double _coutMaintenance, int _productivite, int _nombreEmployes, std::shared_ptr<Produit> _produitType);

	// destructeur
	~Usine();

	// getters

	// r�cup�re le cout de maintenance
	double getCoutMaintenance();
	// r�cup�re la productivit�
	int getProductivite();
	// r�cup�re le nombre d'employ�s
	int getNombreEmployes();
	// r�cup�re le produit fabriqu� par l'usine
	std::shared_ptr<Produit> getProduitType();
	// r�cup�re un produit de fabrication du stock
	std::shared_ptr<Produit> recupererProduitStockProd(int idProduit);
	// r�cup�re la liste des produits fabriqu�s par l'usine
	std::vector<std::shared_ptr<Produit>> getStockProduitsFinis();

	// setters
	// red�fini le cout de maintenance
	void setCoutMaintenance(double _coutMaintenance);
	// red�fini la productivit�
	void setProductivite(int _productivite);
	// red�fini le noombre d'employ�s
	void setNombreEmployes(int _nombreEmployes);
	// red�fini le stock de produits de fabrication
	void setStockProduits(std::vector<std::shared_ptr<Produit>> _produits);
	// ajoute un produit de fabrication au stock
	void ajouterProduit(std::shared_ptr<Produit> produit);
	// red�fini le stock de produits fabriqu�s par l'usine
	void setStockProduitFini(std::vector<std::shared_ptr<Produit>> _produits);
	// ajoute un produit fabriqu� par l'usine au stock
	void ajouterProduitFini(std::shared_ptr<Produit> produit);

	// ajouter une liste de produits de fabrication au stock
	void Usine::ajouterAuStock(std::vector<std::shared_ptr<Produit>> &produits);


	// verifie si l'usine peut produit ce tour-ci
	bool Usine::peutProduire(std::vector<std::pair<std::shared_ptr<Produit>, int>> recette);

	// Produire des produits
	std::vector<std::shared_ptr<Produit>> produire(int salaireEmployes);

	// recuperer des produits fabriqu�s par l'usine
	std::vector<std::shared_ptr<Produit>> recupererProduits();

	// recuperer des produits fabriqu�s par l'usine par quantit�
	std::vector<std::shared_ptr<Produit>> recupererProduits(int quantite);

	// afficher les donn�es d'une usine
	void afficherUsine();

protected:
	double coutMaintenance;
	int productivite;
	int nombreEmployes;

	// stock de produits necessaire pour faire un produit
	std::vector<std::shared_ptr<Produit>> stockProduits;

	// stock de produits fabriqu�s dans l'usine
	std::vector<std::shared_ptr<Produit>> stockProduitsFinis;

	// le produit que l'usine fabrique
	std::shared_ptr<Produit> produitType;
};