#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

void fillArrays(int arr1[], int arr2[], int arr3[], int arr4[], int size) {
    for (int i = 0; i < size; ++i) {
        int randomNum = rand();
        arr1[i] = randomNum;
        arr2[i] = randomNum;
        arr3[i] = randomNum;
        arr4[i] = randomNum;
    }
}

void bubbleSort(int arr[], int size, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            ++comparisons;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

double measureTime(int arr[], int size, int &comparisons) {
    clock_t startTime = clock();

    bubbleSort(arr, size, comparisons); // Replace with your sorting algorithm

    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

void runSortingAlgorithm(int size) {
    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *arr3 = new int[size];
    int *arr4 = new int[size];

    int totalComparisons = 0;
    double totalTime = 0;


    // Sorting over a range from 1,000 to 7,000 in increments of 1,000
    for (int run = 0; run < 10; ++run) {
        fillArrays(arr1, arr2, arr3, arr4, size);

        int comparisons = 0;
        double timeTaken = measureTime(arr1, size, comparisons);

        totalComparisons += comparisons;
        totalTime += timeTaken;
    }

    double avgTime = totalTime / 10;
    double avgComparisons = double(totalComparisons) / 10;

    std::cout << "Array Size: " << size << std::endl;
    std::cout << "Average Time: " << avgTime << " seconds" << std::endl;
    std::cout << "Average Comparisons: " << avgComparisons << std::endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}

int main() {
    // Example usage with array size ranging from 1,000 to 7,000 in increments of 1,000
    for (int size = 1000; size <= 7000; size += 1000) {
        runSortingAlgorithm(size);
        std::cout << std::endl;
    }

    return 0;
}
