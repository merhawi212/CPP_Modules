#include "PmergeMe.hpp"

// Function to merge two halves in merge sort for list
void merge(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right) {
    std::list<int> L(left, mid), R(mid, right);

    std::list<int>::iterator it1 = L.begin(), it2 = R.begin();
    std::list<int>::iterator it = left;

    while (it1 != L.end() && it2 != R.end()) {
        if (*it1 <= *it2) {
            *it++ = *it1++;
        } else {
            *it++ = *it2++;
        }
    }

    while (it1 != L.end()) {
        *it++ = *it1++;
    }

    while (it2 != R.end()) {
        *it++ = *it2++;
    }
}

// Function to perform insertion sort for list
void insertionSort(std::list<int>::iterator left, std::list<int>::iterator right) {
    std::list<int>::iterator it = left;
    ++it; // Start from the second element

    for (; it != right; ++it) {
        int key = *it;
        std::list<int>::iterator jt = it;
        --jt;

        // Shift elements greater than key to the right
        std::list<int>::iterator next_jt = jt;
        ++next_jt;
        while (jt != left && *jt > key) {
            *next_jt = *jt;
            --jt;
            --next_jt;
        }
        *next_jt = key;
    }
}

// Function to perform merge-insert-sort for list
void mergeInsertSort(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right) {
     // Threshold for switching to insertion sort
    if (std::distance(left, right) + 1 <= THERESHOLD) {
        insertionSort(left, right);
    } else {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        mergeInsertSort(lst, left, mid);
     // Manually advancing mid to get the next element after mid
        std::list<int>::iterator next_mid = mid;
        ++next_mid;
        mergeInsertSort(lst, next_mid, right);
        merge(left, mid, right);
		
    }
}
