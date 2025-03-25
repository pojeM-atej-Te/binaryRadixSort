#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Bubble Sort po k-tem bitu
void bubbleSortByBit(vector<unsigned char>& arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            int bit1 = (arr[j] >> k) & 1;
            int bit2 = (arr[j + 1] >> k) & 1;
            if (bit1 > bit2) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Popolni binarni Radix sort
void binaryRadixSort(vector<unsigned char>& arr) {
    for (int k = 0; k < 8; ++k) {
        bubbleSortByBit(arr, k);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uporaba: " << argv[0] << " <vhodna_datoteka>" << endl;
        return 1;
    }

    string vhodna_pot = argv[1];
    ifstream vhodna(vhodna_pot);
    if (!vhodna) {
        cerr << "Napaka pri odpiranju datoteke: " << vhodna_pot << endl;
        return 1;
    }

    vector<unsigned char> stevila;
    string vrstica, stevilo;
    
    // Preberi vsa števila iz datoteke
    while (getline(vhodna, vrstica)) {
        stringstream ss(vrstica);
        while (ss >> stevilo) {
            stevila.push_back(static_cast<unsigned char>(stoi(stevilo)));
        }
    }
    vhodna.close();

    // Izvedi Radix sort
    binaryRadixSort(stevila);

    // Zapiši sortirana števila v datoteko out.txt
    ofstream izhod("out.txt");
    if (!izhod) {
        cerr << "Napaka pri ustvarjanju izhodne datoteke!" << endl;
        return 1;
    }

    for (size_t i = 0; i < stevila.size(); ++i) {
        izhod << (int)stevila[i];
        if (i != stevila.size() - 1) izhod << " ";
    }
    izhod << endl;

    izhod.close();
    cout << "Sortirana števila so zapisana v out.txt" << endl;

    return 0;
}
