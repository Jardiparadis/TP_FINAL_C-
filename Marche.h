#pragma once

#include <iostream>
#include <vector>

#include "Produit.h"

class Entreprise;

class Marche
{
public:
	~Marche();
	static Marche* getInstance();
	void enregistrerEntreprise(const std::shared_ptr<Entreprise>& entreprise);
	void enregistrerProduit(const std::shared_ptr<Produit>& produit);
	std::shared_ptr<Produit> getProduit(int idProduit);

private:
	static Marche* instanceMarche;
	std::vector<std::shared_ptr<Entreprise>> entreprises;
	std::vector<std::shared_ptr<Produit>> produits;

	Marche();
};
