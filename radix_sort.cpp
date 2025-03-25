#include <iostream>
#include <vector>
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

// Popolni binarni Radix sort (iterira skozi vseh 8 bitov)
void binaryRadixSort(vector<unsigned char>& arr) {
    for (int k = 0; k < 8; ++k) {
        bubbleSortByBit(arr, k);
    }
}

int main() {
    vector<unsigned char> arr = {170, 45, 75, 90, 255, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << (int)num << " ";
    }
    cout << endl;

    binaryRadixSort(arr);

    cout << "Sorted array using Binary Radix Sort: ";
    for (int num : arr) {
        cout << (int)num << " ";
    }
    cout << endl;

    return 0;
}
