#include <iostream>

#include "Marche.h"
#include "Entreprise.h"

int main()
{
	auto marche = Marche::getInstance();

	std::shared_ptr<Entreprise> e1(new Entreprise("aa", 20000, 30));
	std::shared_ptr<Produit> p1(new Produit(56));
	e1->creerUsine(1000, 5, 10, p1.get());
	std::shared_ptr<Entreprise> e2(new Entreprise("bb", 22000, 35));
	std::vector<std::pair<Produit*, int>> rec1 = { {p1.get(), 5} };
	std::shared_ptr<Produit> p2(new Produit(56, 20, 0, rec1));
	e2->creerUsine(1200, 2, 12, p2.get());

	marche->creerOrdreDeVente(e1->getNom(), p1, 20, 50);

	std::cout << marche->chercherOrdreDeVentePourProduit(p1)->size() << std::endl;

	e1->fonctionner();
	e2->fonctionner();

	std::cout << e1->getNom() << " : " << std::endl;
	std::cout << "- capital : " << e1->getCapital() << std::endl;

	std::cout << e2->getNom() << " : " << std::endl;
	std::cout << "- capital : " << e2->getCapital() << std::endl;

	return 0;
}