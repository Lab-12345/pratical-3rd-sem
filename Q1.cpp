#include <iostream>

template <typename T>
int linearSearch(const T arr[], int size, const T& key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

template <typename T>
int binarySearch(const T arr[], int size, const T& key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Element found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    const int size = 5;
    int intList[size] = {10, 20, 30, 40, 50};

    std::cout << "Choose search method:" << std::endl;
    std::cout << "1. Linear Search" << std::endl;
    std::cout << "2. Binary Search" << std::endl;

    int choice;
    std::cin >> choice;

    int key;
    std::cout << "Enter the element to search: ";
    std::cin >> key;

    int index;

    switch (choice) {
        case 1:
            index = linearSearch(intList, size, key);
            break;
        case 2:
            index = binarySearch(intList, size, key);
            break;
        default:
            std::cerr << "Invalid choice!" << std::endl;
            return 1;
    }

    if (index != -1) {
        std::cout << "Element found at index " << index << std::endl;
    } else {
        std::cout << "Element not found in the list" << std::endl;
    }

    return 0;
}
