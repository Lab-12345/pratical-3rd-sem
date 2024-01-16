#include <iostream>

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 5;
    int intList[size] = {30, 10, 50, 20, 40};

    std::cout << "Choose sorting method:" << std::endl;
    std::cout << "1. Insertion Sort" << std::endl;
    std::cout << "2. Bubble Sort" << std::endl;
    std::cout << "3. Selection Sort" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(intList, size);
            break;
        case 2:
            bubbleSort(intList, size);
            break;
        case 3:
            selectionSort(intList, size);
            break;
        default:
            std::cerr << "Invalid choice!" << std::endl;
            return 1;
    }

    std::cout << "Sorted array: ";
    printArray(intList, size);

    return 0;
}
