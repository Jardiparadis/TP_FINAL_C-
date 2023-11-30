#include "Marche.h"

Marche::~Marche()
{
	if (instanceMarche)
	{
		delete instanceMarche;
	}
}

Marche* Marche::getInstance()
{
	if (!instanceMarche)
	{
		instanceMarche = new Marche();
	}
	return instanceMarche;
}

void Marche::enregistrerEntreprise(const std::shared_ptr<Entreprise>& entreprise)
{
	entreprises.push_back(entreprise);
}	

Marche::Marche()
{
}

Marche* Marche::instanceMarche = NULL;