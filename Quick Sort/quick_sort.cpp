#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Quick Sort Algorithm
 * Time Complexity: O(n log n) average case, O(n²) worst case
 * Space Complexity: O(log n)
 */
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Utility function to print array
 */
void printArray(const vector<int>& arr, const string& sortName) {
    cout << sortName << " result: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * Function to create a copy of original array for testing
 */
vector<int> copyArray(const vector<int>& original) {
    return vector<int>(original);
}

int main() {
    cout << "\n=== Quick Sorting Algorithm Demonstration ===\n" << endl;
    
    // Test data
    vector<int> originalArr = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42, 30, 5, 77, 55};
    
    cout << "Original array: ";
    for (int num : originalArr) {
        cout << num << " ";
    }
    cout << "\n" << endl;
    
    // Test Quick Sort
    vector<int> arr1 = copyArray(originalArr);
    quickSort(arr1, 0, arr1.size() - 1);
    printArray(arr1, "Quick Sort");
    
   
    
    cout << "\n=== Performance Analysis ===\n";
    cout << "Quick Sort: Average O(n log n), Worst O(n^2)" << endl;
    
    
    return 0;
}