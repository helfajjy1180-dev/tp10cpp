
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Donner la taille du tableau : ";
    cin >> n;

    if (n <= 0) {
        cout << "Taille invalide !" << endl;
        return 0;
    }

    int* T = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "T[" << i << "] = ";
        cin >> T[i];
    }

    cout << "Les elements du tableau sont : " << endl;

    for (int i = 0; i < n; i++) {
        cout << T[i] << " ";
    }

    delete[] T;

    return 0;
}
