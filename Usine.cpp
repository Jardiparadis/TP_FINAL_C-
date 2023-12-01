#include <iostream>
#include <vector>
#include "Usine.h"

// constructeur
Usine::Usine(double _coutMaintenance, int _productivite, int _nombreEmployes, std::shared_ptr<Produit> _produitType)
{
	coutMaintenance = _coutMaintenance;
	productivite = _productivite;
	nombreEmployes = _nombreEmployes;
	produitType = _produitType;
}

Usine::~Usine()
{
	stockProduits.clear();
}

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
std::vector<std::shared_ptr<Produit>> Usine::getStockProduitsFinis()
{
	std::vector<std::shared_ptr<Produit>> tempoStockProduits = stockProduitsFinis;
	return tempoStockProduits;
}

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

	// clear de la liste de produits passé en parametre car transfet des produits
	produits.clear();
}

bool Usine::peutProduire(std::vector<std::pair<std::shared_ptr<Produit>, int>> recette)
{
	// si matiere premiere
	if (recette.size() == NULL)
	{
		return true;
	}

	// stock permettant de garder tous les produits necessaires a la production ( à la recette)
	std::vector<std::shared_ptr<Produit>> stockTemporaire = stockProduits;

	for (int i = 0; i < productivite; i++)
	{
		for (std::pair<std::shared_ptr<Produit>, int> produit : recette)
		{
			for (int j = 0; j < produit.second; j++)
			{
				// recuperer un produit de la recette et le supprimer
				std::shared_ptr<Produit> prodAUtiliser;
				auto iterator = std::begin(stockTemporaire);
				while (iterator != std::end(stockTemporaire))
				{
					// si le produit est bien dans la recette
					if ((*iterator)->getId() == produit.first->getId())
					{
						prodAUtiliser = (*iterator);
						stockTemporaire.erase(iterator);
						break;
					}
					iterator++;
				}

				// si le produit n'est pas dans la recette
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

std::vector<std::shared_ptr<Produit>> Usine::produire(int salaireEmployes)
{
	std::vector<std::shared_ptr<Produit>> stockAjoutFinal;
	double coutProductionTotal = coutMaintenance + (salaireEmployes * nombreEmployes);
	std::vector<std::pair<std::shared_ptr<Produit>, int>> recette = produitType->getRecette();

	// s'il n'a pas assez de produit de fabrication pour faire la recette
	// ou s'il a une productivité nulle
	if (!peutProduire(recette) || productivite == 0)
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
		for (std::pair<std::shared_ptr<Produit>, int> produit : recette)
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
	produitType->setCoutDeProduction(stockAjoutFinal.at(0)->getCoutDeProduction());
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

void Usine::afficherUsine()
{
	std::cout << "Nombre d'employes :\t" << nombreEmployes << "\n" << std::endl;
	std::cout << "Fabrique :\t" << " le produit #" << produitType->getId() << " )\n" << std::endl;
	std::cout << "Niveau de productivite :\t" << productivite << "\n" << std::endl;
	std::cout << "Dernier cout de Maintenance :\t" << coutMaintenance << "$ \n" << std::endl;
	
	std::cout << "\n" << std::endl;
}