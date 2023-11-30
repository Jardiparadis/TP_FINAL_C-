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
	static std::shared_ptr<Marche> getInstance();
	void enregistrerEntreprise(const std::shared_ptr<Entreprise>& entreprise);
	void enregistrerProduit(const std::shared_ptr<Produit>& produit);
	std::shared_ptr<Produit> getProduit(int idProduit);
	void creerOrdreDeVente(std::shared_ptr<Entreprise> entreprise, std::shared_ptr<Produit> produit, int quantity, double prix);
	std::shared_ptr<std::vector<OrdreVente>> chercherOrdreDeVentePourProduit(std::shared_ptr<Produit> produit);
	void acheterOrdreDeVente(std::shared_ptr<Entreprise> entrepriseAcheteuse, std::shared_ptr<Entreprise> entrepriseVendeuse, std::shared_ptr<Produit> produit);
private:
	static std::shared_ptr<Marche> instanceMarche;
	std::vector<std::shared_ptr<Entreprise>> entreprises;
	std::vector<std::shared_ptr<Produit>> produits;
	std::vector<OrdreVente> ordresVente;
	Marche();
};
