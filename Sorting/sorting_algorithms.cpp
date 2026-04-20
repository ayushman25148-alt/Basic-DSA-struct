// Sorting Algorithms - Basic Implementations
// Includes: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort
#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i < (int)arr.size() - 1) cout << " ";
    }
    cout << endl;
}

// Bubble Sort - O(n^2)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Already sorted
    }
}

// Selection Sort - O(n^2)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort - O(n^2)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort Helper - O(n log n)
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int>& arr) {
    if (arr.size() > 1)
        mergeSort(arr, 0, arr.size() - 1);
}

// Quick Sort Helper - O(n log n) average
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
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

void quickSort(vector<int>& arr) {
    if (arr.size() > 1)
        quickSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> original = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array:    ";
    printArray(original);

    vector<int> arr;

    arr = original;
    bubbleSort(arr);
    cout << "Bubble Sort:       ";
    printArray(arr);

    arr = original;
    selectionSort(arr);
    cout << "Selection Sort:    ";
    printArray(arr);

    arr = original;
    insertionSort(arr);
    cout << "Insertion Sort:    ";
    printArray(arr);

    arr = original;
    mergeSort(arr);
    cout << "Merge Sort:        ";
    printArray(arr);

    arr = original;
    quickSort(arr);
    cout << "Quick Sort:        ";
    printArray(arr);

    return 0;
}
