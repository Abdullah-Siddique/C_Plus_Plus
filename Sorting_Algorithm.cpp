#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 1. Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 3. Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 4. Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 5. Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
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

// 6. Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 8. Radix Sort
int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int num : arr) {
        if (num > mx)
            mx = num;
    }
    return mx;
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

// Main function to test the sorting algorithms
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    // Bubble Sort
    vector<int> bubbleSortedArray = arr;
    bubbleSort(bubbleSortedArray);
    cout << "Bubble Sorted array: ";
    printArray(bubbleSortedArray);

    // Selection Sort
    vector<int> selectionSortedArray = arr;
    selectionSort(selectionSortedArray);
    cout << "Selection Sorted array: ";
    printArray(selectionSortedArray);

    // Insertion Sort
    vector<int> insertionSortedArray = arr;
    insertionSort(insertionSortedArray);
    cout << "Insertion Sorted array: ";
    printArray(insertionSortedArray);

    // Merge Sort
    vector<int> mergeSortedArray = arr;
    mergeSort(mergeSortedArray, 0, mergeSortedArray.size() - 1);
    cout << "Merge Sorted array: ";
    printArray(mergeSortedArray);

    // Quick Sort
    vector<int> quickSortedArray = arr;
    quickSort(quickSortedArray, 0, quickSortedArray.size() - 1);
    cout << "Quick Sorted array: ";
    printArray(quickSortedArray);

    // Heap Sort
    vector<int> heapSortedArray = arr;
    heapSort(heapSortedArray);
    cout << "Heap Sorted array: ";
    printArray(heapSortedArray);

    // Shell Sort
    vector<int> shellSortedArray = arr;
    shellSort(shellSortedArray);
    cout << "Shell Sorted array: ";
    printArray(shellSortedArray);

    // Radix Sort
    vector<int> radixSortedArray = arr;
    radixSort(radixSortedArray);
    cout << "Radix Sorted array: ";
    printArray(radixSortedArray);

    return 0;
}
/* 
Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order.
Selection Sort: Selects the minimum element from the unsorted part and swaps it with the first unsorted element.
Insertion Sort: Builds the sorted array one element at a time by inserting elements into their correct positions.
Merge Sort: Divides the array into two halves, recursively sorts them, and then merges the sorted halves.
Quick Sort: Picks a pivot element, partitions the array around the pivot, and recursively sorts the subarrays.
Heap Sort: Builds a max heap from the array and repeatedly extracts the maximum element to sort the array.
Shell Sort: Generalization of insertion sort that allows the exchange of far-apart elements.
Radix Sort: Sorts the numbers digit by digit starting from the least significant digit.
*/
