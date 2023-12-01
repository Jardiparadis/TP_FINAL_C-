#include <iostream>
#include "marche.h"

//#include "map.h"

int main()
{

	auto marche = Marche::getInstance();

	std::vector<std::pair<Produit*, int>> recetteBrut;
	Produit p1(0, 1, 2, recetteBrut);
	Produit p2(3, 4, 5, recetteBrut);

	std::vector<std::pair<Produit*, int>> recetteComposee = {
		std::make_pair(&p1, 2),
		std::make_pair(&p2, 3)
	};
	Produit p3(6, 7, 8, recetteComposee);

	marche->enregistrerProduit(std::make_shared<Produit>(p1));
	marche->enregistrerProduit(std::make_shared<Produit>(p2));
	marche->enregistrerProduit(std::make_shared<Produit>(p3));

	Entreprise tardis("TARDIS Enterprise", 424242, 100);
	//tardis.creerUsine(1200, 12, 6, p3);
	tardis.afficherBilan();

	std::cout << marche->getProduit(6)->getCoutDeBase() << std::endl;

	return 0;
}