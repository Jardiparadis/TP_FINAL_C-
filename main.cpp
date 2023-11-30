#include <iostream>
#include "marche.h"

int main()
{
	auto marche = Marche::getInstance();

	std::shared_ptr<Entreprise> e1(new Entreprise("aa", 20000, 30));
	std::shared_ptr<Produit> p1(new Produit(56));

	marche->creerOrdreDeVente(e1, p1, 20, 50);

	std::cout << marche->chercherOrdreDeVentePourProduit(p1)->size() << std::endl;

	return 0;
}