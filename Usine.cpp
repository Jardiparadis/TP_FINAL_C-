#include <iostream>
#include <vector>
#include "Usine.h"

int Produit::getId()
{
	return id;
}
double Produit::getCoutDeBase()
{
	return coutDeBase;
}
double Produit::getCoutDeProduction()
{
	return coutDeProduction; 
}

void Produit::setCoutDeProduction(double coutDeProd)
{
	coutDeProduction = coutDeProd;
}

Produit::Produit(int _id)
{
	id = _id;
	coutDeBase = 0;
	coutDeProduction = 0;
}

Produit::~Produit()
{

}



Usine::Usine(double _coutMaintenance, int _productivite, int _nombreEmployes, std::shared_ptr<Produit> _produitType)
{
	coutMaintenance = _coutMaintenance;
	productivite = _productivite;
	nombreEmployes = _nombreEmployes;
	produitType = _produitType;
}

// destructeur
Usine::~Usine()
{
	stockProduits.clear();
}

// getters
double Usine::getCoutMaintenance()
{
	return coutMaintenance;
}
int Usine::getProductivite()
{
	return productivite;
}
int Usine::getNombreEmployes()
{
	return nombreEmployes;
}
std::shared_ptr<Produit> Usine::getProduitType() 
{
	return produitType;
}

// setters
void Usine::setCoutMaintenance(double _coutMaintenance)
{
	coutMaintenance = _coutMaintenance;
}
void Usine::setProductivite(int _productivite)
{
	productivite = productivite;
}
void Usine::setNombreEmployes(int _nombreEmployes)
{
	nombreEmployes = _nombreEmployes;
}
void Usine::setStockProduits(std::vector<std::shared_ptr<Produit>> _produits)
{
	stockProduits = _produits;
}
void Usine::ajouterProduit(std::shared_ptr<Produit> produit)
{
	stockProduits.push_back(produit);
}
void Usine::setStockProduitFini(std::vector<std::shared_ptr<Produit>> _produits)
{
	stockProduitsFinis = _produits;
}
void Usine::ajouterProduitFini(std::shared_ptr<Produit> produit)
{
	stockProduitsFinis.push_back(produit);
}

// recuperer produit de fabrication au stock
std::shared_ptr<Produit> Usine::recupererProduitStockProd(int idProduit)
{
	std::shared_ptr<Produit> prodARecuperer;
	auto iterator = std::begin(stockProduitsFinis);
	while (iterator != std::end(stockProduits))
	{
		if ((*iterator)->getId() == idProduit)
		{
			prodARecuperer = (*iterator);
			stockProduits.erase(iterator);
			break;
		}
	}
	return prodARecuperer;
}

// Produire des produits
std::vector<std::shared_ptr<Produit>> Usine::produire(std::vector<std::pair<Produit*, int>> recette, int salaireEmployes)
{
	std::vector<std::shared_ptr<Produit>> stockAjoutFinal;
	double coutProductionTotal = coutMaintenance * salaireEmployes * nombreEmployes;

	// verifie si c'est une matiere premiere (recette vide)
	if (recette.size() == NULL)
	{
		for (int i = 0; i < productivite; i++)
		{
			stockAjoutFinal.push_back(std::make_shared<Produit>(produitType->getId()));
		}
		goto calculCoutProd;
	}

	// commencer la boucle pour ajouter des produits
	for (int i = 0; i < productivite; i++)
	{
		std::vector<std::shared_ptr<Produit>> stockTemporaire;
		for (std::pair<Produit*, int> produit : recette)
		{
			for(int j = 0; j < produit.second; i++)
			{
				// recuperer un produit de fabrication pour l'utiliser
				std::shared_ptr<Produit> prodAUtiliser = recupererProduitStockProd(produit.first->getId());
				if (prodAUtiliser != nullptr)
				{
					stockTemporaire.push_back(prodAUtiliser);
					coutProductionTotal += prodAUtiliser->getCoutDeBase();
				}
				else
				{
					std::cout << "pas assez de produit pour creer le nouveau" << std::endl;

					// remettre les produits dans le stock de fabrication
					for (std::shared_ptr<Produit> produitARemettre : stockTemporaire)
					{
						stockProduits.push_back(produitARemettre);

					}
					goto calculCoutProd;
				}
			}
		}
		stockAjoutFinal.push_back(std::make_shared<Produit>(produitType->getId()));
	}

	// calculer le cout de production de chaque produit
	calculCoutProd:
	coutProductionTotal += produitType->getCoutDeBase() * stockAjoutFinal.size();
	for (std::shared_ptr<Produit> prodFinal : stockAjoutFinal)
	{
		prodFinal->setCoutDeProduction(coutProductionTotal / stockAjoutFinal.size());
	}
	stockProduitsFinis.insert(std::end(stockProduitsFinis), std::begin(stockAjoutFinal), std::end(stockAjoutFinal));
	return stockAjoutFinal;
}

std::vector<std::shared_ptr<Produit>> Usine::recupererProduits(Produit produit, int quantite)
{
	// Calcul du cout de production du produit
	int idProduit = produit.getId();
	std::vector<std::shared_ptr<Produit>> produitsARecuperer;

	// parcourir le stockage pour recuperer les produits
	auto iterator = std::begin(stockProduitsFinis);
	int nbProduitsSupprimes = 0;
	while (iterator != std::end(stockProduitsFinis))
	{
		if ((*iterator)->getId() == idProduit)
		{
			produitsARecuperer.push_back(*iterator);
			stockProduits.erase(iterator);
			nbProduitsSupprimes++;
		}
			
	}
	return produitsARecuperer;
}