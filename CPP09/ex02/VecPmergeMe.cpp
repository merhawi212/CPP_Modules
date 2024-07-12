#include "PmergeMe.hpp"

// Function to merge two halves in merge sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
		 L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
		 R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
			arr[k++] = L[i++];
        else 
			arr[k++] = R[j++];
    }

    while (i < n1)
		 arr[k++] = L[i++];
    while (j < n2) 
		arr[k++] = R[j++];
}


// Function to perform insertion sort
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Function to perform merge-insert sort (Ford-Johnson algorithm)
void mergeInsertSort(std::vector<int>& arr, int left, int right) {
      // Threshold for switching to insertion sort
    if (right - left + 1 <= THERESHOLD) {
        insertionSort(arr, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeInsertSort(arr, left, mid);
        mergeInsertSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
