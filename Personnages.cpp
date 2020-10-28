#include "Personnages.hpp"
#include <iostream>

using namespace std;

Entite::Entite() : c_vie(100), c_att(1), c_def(1)
{
    
}
Entite::Entite(int vie, int att, int def, std::string nom, std::string classe) : c_vie(vie), c_att(att), c_def(def), c_nom(nom), c_classe(classe) 
{
    
}
Entite::~Entite()
{
    cout << "Suppresion du personnage de la RAM" << endl;
}
void Entite::tuer()
{
    this->c_vie = 0;
}
bool Entite::estEnVie()
{
    if (this->c_vie <= 0)
        return false;
    else
        return true;
}
void Entite::recevoirDegats(int degats)
{
    int degatsAttenues = degats - this->c_def;
    if (degatsAttenues < 0) degatsAttenues = 0;
    if (this->c_vie - degatsAttenues <= 0)
    {
        this->c_vie = 0;
        cout << this->c_nom << " n a pas survecu " << endl;
        this->~Entite();
    }
    else
    {
        this->c_vie -= degatsAttenues;
        cout << this->c_nom << " a survecu" << endl;
    }
}
void Entite::attaque(Entite& cible)
{
    cout << this->c_nom << " a inflige une attaque de " << this->c_att << endl; 
    cible.recevoirDegats(this->c_att);
}
void Entite::afficherVie() {
    if (this->estEnVie())
    cout << this->c_nom << " a actuellement " << this->c_vie << " HP" << endl;
}
