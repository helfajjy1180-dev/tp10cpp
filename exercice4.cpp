
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    string getNom() {
        return nom;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

void ajouterContact(Contact** carnet, int& nb) {
    string nom, telephone, email;

    cout << "Donner le nom : ";
    getline(cin, nom);

    cout << "Donner le telephone : ";
    getline(cin, telephone);

    cout << "Donner l'email : ";
    getline(cin, email);

    carnet[nb] = new Contact(nom, telephone, email);
    nb++;
}

void afficherContacts(Contact** carnet, int nb) {
    for (int i = 0; i < nb; i++) {
        cout << "\nContact " << i + 1 << endl;
        carnet[i]->afficher();
    }
}

void supprimerContact(Contact** carnet, int& nb, string nom) {
    for (int i = 0; i < nb; i++) {
        if (carnet[i]->getNom() == nom) {
            delete carnet[i];

            for (int j = i; j < nb - 1; j++) {
                carnet[j] = carnet[j + 1];
            }

            nb--;

            cout << "Contact supprime !" << endl;
            return;
        }
    }

    cout << "Contact introuvable !" << endl;
}

int main() {
    int capacite = 100;
    int nb = 0;

    Contact** carnet = new Contact*[capacite];

    int choix;

    do {
        cout << "\n--- CARNET D'ADRESSES ---" << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
        case 1:
            if (nb < capacite) {
                ajouterContact(carnet, nb);
            } else {
                cout << "Carnet plein !" << endl;
            }
            break;

        case 2:
            afficherContacts(carnet, nb);
            break;

        case 3: {
            string nom;
            cout << "Nom du contact a supprimer : ";
            getline(cin, nom);

            supprimerContact(carnet, nb, nom);
            break;
        }

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    for (int i = 0; i < nb; i++) {
        delete carnet[i];
    }

    delete[] carnet;

    return 0;
}
