#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include "Produit.h"
#include "Entreprise.h"
#include "OrdreVente.h"

class Marche
{
public:
	~Marche();
	static Marche* getInstance();
	void enregistrerEntreprise(const std::shared_ptr<Entreprise>& entreprise);
	void enregistrerProduit(const std::shared_ptr<Produit>& produit);
	std::shared_ptr<Produit> getProduit(int idProduit);
	void creerOrdreVente(std::shared_ptr<Entreprise> entreprise, std::shared_ptr<Produit> produit, int quantite, double prix);

private:
	static Marche* instanceMarche;
	std::vector<std::shared_ptr<Entreprise>> entreprises;
	std::vector<std::shared_ptr<Produit>> produits;
	std::vector<std::shared_ptr<OrdreVente>> misesenVente;
	Marche();
};
