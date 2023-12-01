#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include "Produit.h"
#include "OrdreVente.h"

// Classe singleton
class Marche
{
public:
	~Marche();
	// Récupère l'instance de singleton
	static std::shared_ptr<Marche> getInstance();
	// Enregistrer un nouveau produit sur le marche
	void enregistrerProduit(const std::shared_ptr<Produit>& produit);
	std::shared_ptr<Produit> getProduit(int idProduit);

	/*
	* Le système d'achat / revente de ressources fonctionne grâce à un système d'ordres de vente.
	* Un ordre de vente correspond à un produit qu'une entreprise met à la vente contre un certain prix.
	* Les autres entreprises peuvent ensuite consulter ces ordres de vente et décider lequel acheter.
	* Idéalement, je pense que le système d'achat / vente aurait dû être réaliser avec une classe Observer, pour notifier quand une offre est achetée ou vendue
	*/
	// Créer un ordre de vente
	void creerOrdreDeVente(std::string nomEntreprise, std::shared_ptr<Produit> produit, int quantity, double prix);
	// Rechercher des ordres de ventes
	std::shared_ptr<std::vector<OrdreVente>> chercherOrdreDeVentePourProduit(std::shared_ptr<Produit> produit);
	// Acheter un ordre de vente
	void acheterOrdreDeVente(std::string nomEntrepriseAcheteuse, std::string nomEntrepriseVendeuse, std::shared_ptr<Produit> produit);
private:
	static std::shared_ptr<Marche> instanceMarche;
	std::vector<std::shared_ptr<Produit>> produits;
	std::vector<OrdreVente> ordresVente;
	Marche();
};
