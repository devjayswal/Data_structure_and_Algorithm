#include <iostream>
#include <ctime>
using namespace std;

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 5, 9, 12, 17, 20, 23, 25, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    clock_t start = clock();
    int linear_search_idx = linear_search(arr, size, target);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000000;

    cout << "Linear Search:" << endl;
    if (linear_search_idx != -1) {
        cout << "Element found at index " << linear_search_idx << endl;
    } else {
        cout << "Element not found" << endl;
    }
    cout << "Execution time: " << duration << " microseconds" << endl;

    start = clock();
    int binary_search_idx = binary_search(arr, size, target);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC * 1000000;

    cout << "Binary Search:" << endl;
    if (binary_search_idx != -1) {
        cout << "Element found at index " << binary_search_idx << endl;
    } else {
        cout << "Element not found" << endl;
    }
    cout << "Execution time: " << duration << " microseconds" << endl;

    return 0;
}
