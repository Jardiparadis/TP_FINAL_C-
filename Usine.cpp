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



Usine::Usine(double _coutMaintenance, int _productivite, int _nombreEmployes, Produit* _produitType)
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
	delete produitType;
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
Produit* Usine::getProduitType()
{
	return produitType;
}
std::vector<std::shared_ptr<Produit>> Usine::getStockProduitsFinis()
{
	std::vector<std::shared_ptr<Produit>> tempoStockProduits = stockProduitsFinis;
	return tempoStockProduits;
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

void Usine::ajouterAuStock(std::vector<std::shared_ptr<Produit>>& produits)
{
	stockProduits.insert(std::end(stockProduits), std::begin(produits), std::end(produits));
	produits.clear();
}

// recuperer produit de fabrication au stock
std::shared_ptr<Produit> Usine::recupererProduitStockProd(int idProduit)
{
	std::shared_ptr<Produit> prodARecuperer;
	auto iterator = std::begin(stockProduits);
	while (iterator != std::end(stockProduits))
	{
		if ((*iterator)->getId() == idProduit)
		{
			prodARecuperer = (*iterator);
			stockProduits.erase(iterator);
			break;
		}
		iterator++;
	}
	return prodARecuperer;
}

bool Usine::peutProduire(std::vector<std::pair<Produit*, int>> recette)
{
	// si matiere premiere
	if (recette.size() == NULL)
	{
		return true;
	}

	std::vector<std::shared_ptr<Produit>> stockTemporaire = stockProduits;

	for (int i = 0; i < productivite; i++)
	{
		for (std::pair<Produit*, int> produit : recette)
		{
			for (int j = 0; j < produit.second; j++)
			{
				// recuperer un produit de la recette et le supprimer
				std::shared_ptr<Produit> prodAUtiliser;
				auto iterator = std::begin(stockTemporaire);
				while (iterator != std::end(stockTemporaire))
				{
					if ((*iterator)->getId() == produit.first->getId())
					{
						prodAUtiliser = (*iterator);
						stockTemporaire.erase(iterator);
						break;
					}
					iterator++;
				}
				if (prodAUtiliser == nullptr)
				{
					std::cout << "l'entreprise ne peux pas produire, pas assez de stock de produits de fabrication" << std::endl;
					return false;
				}
			}
		}
	}

	return true;
}



// Produire des produits
std::vector<std::shared_ptr<Produit>> Usine::produire(int salaireEmployes)
{
	std::vector<std::shared_ptr<Produit>> stockAjoutFinal;
	double coutProductionTotal = coutMaintenance + (salaireEmployes * nombreEmployes);
	std::vector<std::pair<Produit*, int>> recette = produitType->getRecette();

	if (!peutProduire(recette))
	{
		return stockAjoutFinal;
	}

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
			for (int j = 0; j < produit.second; j++)
			{
				// recuperer un produit de fabrication pour l'utiliser
				std::shared_ptr<Produit> prodAUtiliser = recupererProduitStockProd(produit.first->getId());
				coutProductionTotal += prodAUtiliser->getCoutDeBase();
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

std::vector<std::shared_ptr<Produit>> Usine::recupererProduits()
{
	std::vector<std::shared_ptr<Produit>> tempoStockProduits = stockProduitsFinis;
	stockProduitsFinis.erase(stockProduitsFinis.begin(), stockProduitsFinis.end());
	return tempoStockProduits;
}

std::vector<std::shared_ptr<Produit>> Usine::recupererProduits(int quantite)
{
	std::vector<std::shared_ptr<Produit>> tempoStockProduits = stockProduitsFinis;
	stockProduitsFinis.erase(stockProduitsFinis.begin(), stockProduitsFinis.begin() + quantite);
	return tempoStockProduits;
}