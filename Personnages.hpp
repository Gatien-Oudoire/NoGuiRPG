#ifndef PERSONNAGES
#define PERSONNAGES

#include <string>

class Entite
{
public:
    Entite();
    Entite(int vie, int att, int def, std::string nom, std::string classe);
    ~Entite();
    bool estEnVie();
    void tuer();
    void recevoirDegats(int degats);
    void attaque(Entite& cible);
    void afficherVie();
    std::string c_classe;
    std::string c_nom;

private:
    int c_vie;
    int c_att;
    int c_def;
};

#endif