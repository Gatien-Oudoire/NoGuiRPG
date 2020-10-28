#include <iostream>
#include "Personnages.hpp"

using namespace std;

int main()
{
    string nomPerso;
    int classeChoix;
    cout << "Bienvenue dans le RPG de gatien " << endl;
    cout << "Entrez le nom de votre personnage" << endl;
    cin >> nomPerso;
    cout << endl
         << nomPerso << " rejoins l aventure !" << endl
         << endl;
    cout << "Voici les differentes classes : " << endl
         << "1 Tank" << endl
         << "2 DPS" << endl
         << "3 Equilibre" << endl;
    cout << "Entrez le numero de la classe que vous voulez jouer" << endl;
    cin >> classeChoix;
    int vie;
    int att;
    int def;
    string classeTxt;
    while (classeChoix != 1 && classeChoix != 2 && classeChoix != 3)
    {
        cout << "Entrez le numero de la classe !!!" << endl;
        cin >> classeChoix;
    }
    if (classeChoix == 1)
    {
        vie = 110;
        att = 20;
        def = 15;
        classeTxt = "tank";
        cout << "Vous avez choisi de jouer tank" << endl;
    }
    else if (classeChoix == 2)
    {
        vie = 100;
        att = 45;
        def = 10;
        classeTxt = "DPS";
        cout << "Vous avez choisi de jouer DPS" << endl;
    }
    else if (classeChoix == 3){
        vie = 100;
        att = 25;
        def = 13;
        classeTxt = "equilibre";
        cout << "Vous avez choisi de jouer equilibre" << endl;

    }
    cout << endl << "---JEU---" << endl;
    Entite joueur(vie, att, def, nomPerso, classeTxt); // creation du joueur en fonction de la classe qu il a choisi
    Entite ennemiUn(50, 5, 5, "Ennemi 1", "Gobelin");
    while (joueur.estEnVie() && ennemiUn.estEnVie())
    {
        joueur.attaque(ennemiUn);
        ennemiUn.afficherVie();
        cout << endl;
        ennemiUn.attaque(joueur);
        joueur.afficherVie();
        cout << endl;
    }
    if (joueur.estEnVie())
    {
        cout << "(-: " <<  joueur.c_nom << " remporte la partie :-)" << endl;
    }
    else
    {
        cout << "(-: " << ennemiUn.c_nom << " remporte la partie :-)" << endl;
    }

    return 0;
}