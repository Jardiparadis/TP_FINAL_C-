#pragma once

class Produit
{
protected:
	int id;
	double coutDeBase;
	double coutDeProduction;
public:
	Produit(int id);
	~Produit();
	int getId();
	double getCoutDeBase();
	double getCoutDeProduction();

	void setCoutDeProduction(double coutDeProd);
};

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

	// setters
	void setCoutMaintenance(double _coutMaintenance);
	void setProductivite(int _productivite);
	void setNombreEmployes(int _nombreEmployes);
	void setStockProduits(std::vector<std::shared_ptr<Produit>> _produits);
	void ajouterProduit(std::shared_ptr<Produit> produit);
	void setStockProduitFini(std::vector<std::shared_ptr<Produit>> _produits);
	void ajouterProduitFini(std::shared_ptr<Produit> produit);

	// recuperer produit de fabrication au stock
	std::shared_ptr<Produit> recupererProduitStockProd(int idProduit);

	// Produire des produits
	std::vector<std::shared_ptr<Produit>> produire(std::vector<std::pair<Produit*, int>> recette, int salaireEmployes);

	std::vector<std::shared_ptr<Produit>> recupererProduits(Produit produit, int quantite);


protected:
	double coutMaintenance;
	int productivite;
	int nombreEmployes;
	std::vector<std::shared_ptr<Produit>> stockProduits;
	std::vector<std::shared_ptr<Produit>> stockProduitsFinis;
	std::shared_ptr<Produit> produitType;
};