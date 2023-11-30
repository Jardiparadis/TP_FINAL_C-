#pragma once

#include <iostream>
#include <vector>

class Produit;
class Entreprise;

class Recette
{
public:
private:
	std::shared_ptr<Produit> resultat;
	std::vector<std::pair<std::shared_ptr<Produit>, int>> ingredients;
};

class Marche
{
public:
	~Marche();
	static Marche* getInstance();
	void enregistrerEntreprise(const std::shared_ptr<Entreprise>& entreprise);
	void enregistrerProduit(int idProduit, int coutBase);
	void enregistrerRecette(const std::shared_ptr<Entreprise>& recette);

private:
	static Marche* instanceMarche;
	std::vector<std::shared_ptr<Entreprise>> entreprises;
	std::vector<std::shared_ptr<Recette>> recettes;
	// [ <Produit, coût> ]
	std::vector<std::pair<std::shared_ptr<Produit>, double>> produits;

	Marche();
};
