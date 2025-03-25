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

int main(){
    
    cout << "Hello world!"<<endl;

    return 0;
}