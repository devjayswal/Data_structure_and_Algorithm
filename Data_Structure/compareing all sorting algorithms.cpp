#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

// functionn of  Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// function of  Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

//function of  Insertion Sort
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

// funtion of  Merge Sort
//Mergeing algrithm
void merge(vector<int>& arr, int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    vector<int> left(leftSize);
    vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
//finally merge sort funtion for sorting
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Quick Sort
//partition algorithm for quick sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}
//finally quick sort funtion for sorting
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Heap Sort
//heapify algorithm for heap sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

//finally heap sort funtion for sorting
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Counting Sort
void countingSort(vector<int>& arr) {
    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort
//count sort algorithm for radix sort
void radixCountSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        radixCountSort(arr, exp);
    }
}

// Bucket Sort
void bucketSort(vector<int>& arr, int numBuckets) {
    int n = arr.size();
    vector<vector<int>> buckets(numBuckets);

    for (int i = 0; i < n; i++) {
        int bucketIdx = arr[i] * numBuckets / (INT_MAX + 1);
        buckets[bucketIdx].push_back(arr[i]);
    }

    for (int i = 0; i < numBuckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int idx = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx] = buckets[i][j];
            idx++;
        }
    }
}

// Display Array
void displayArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 9, 2, 5, 1, 8, 4, 7, 6, 3 };
    vector<int> arr2;

    // Bubble Sort
    cout << "Bubble Sort:" << endl;
    arr2 = arr;
    bubbleSort(arr2);
    displayArray(arr2);
    cout << endl;

    // Selection Sort
    cout << "Selection Sort:" << endl;
    arr2 = arr;
    selectionSort(arr2);
    displayArray(arr2);
    cout << endl;

    // Insertion Sort
    cout << "Insertion Sort:" << endl;
    arr2 = arr;
    insertionSort(arr2);
    displayArray(arr2);
    cout << endl;

    // Merge Sort
    cout << "Merge Sort:" << endl;
    arr2 = arr;
    mergeSort(arr2, 0, arr2.size() - 1);
    displayArray(arr2);
    cout << endl;

    // Quick Sort
    cout << "Quick Sort:" << endl;
    arr2 = arr;
    quickSort(arr2, 0, arr2.size() - 1);
    displayArray(arr2);
    cout << endl;

    // Heap Sort
    cout << "Heap Sort:" << endl;
    arr2 = arr;
    heapSort(arr2);
    displayArray(arr2);
    cout << endl;

    // Counting Sort
    cout << "Counting Sort:" << endl;
    arr2 = arr;
    countingSort(arr2);
    displayArray(arr2);
    cout << endl;

    // Radix Sort
    cout << "Radix Sort:" << endl;
    arr2 = arr;
    radixSort(arr2);
    displayArray(arr2);
    cout << endl;

    // Bucket Sort
    cout << "Bucket Sort:" << endl;
    arr2 = arr;
    bucketSort(arr2, 4);
    displayArray(arr2);
    cout << endl;

    return 0;
}
