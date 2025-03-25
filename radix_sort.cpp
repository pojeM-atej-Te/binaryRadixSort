#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Bubble sort by k-th bit (for later use in Radix Sort)
void bubbleSortByBit(vector<unsigned char>& arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Extract k-th bit for comparison
            int bit1 = (arr[j] >> k) & 1;
            int bit2 = (arr[j + 1] >> k) & 1;
            
            // Stable sort: swap if bit1 > bit2
            // If bits are equal, maintain original order
            if (bit1 > bit2) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Test Radix Sort
    vector<unsigned char> radixSortArr = {170, 45, 75, 90, 255, 24, 2, 66};
    cout << "Original array for Radix Sort: ";
    for (int num : radixSortArr) {
        cout << (int)num << " "; // Cast to int for proper display
    }
    cout << endl;

    // Assuming radixSort is implemented
    bubbleSortByBit(radixSortArr, 0);
    
    cout << "Sorted array using Radix Sort: ";
    for (int num : radixSortArr) {
        cout << (int)num << " "; // Cast to int for proper display
    }
    cout << endl;
    
    return 0;
}