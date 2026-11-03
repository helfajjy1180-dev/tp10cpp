
#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    float prix;

public:
    Livre() {
        titre = "";
        prix = 0;
    }

    void saisir() {
        cout << "Donner le titre : ";
        getline(cin, titre);

        cout << "Donner le prix : ";
        cin >> prix;
        cin.ignore();
    }

    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;

    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Nombre invalide !" << endl;
        return 0;
    }

    Livre* livres = new Livre[n];

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << endl;
        livres[i].saisir();
    }

    cout << "\nListe des livres :" << endl;

    for (int i = 0; i < n; i++) {
        livres[i].afficher();
    }

    delete[] livres;

    return 0;
}
