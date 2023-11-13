#include <iostream>

void mergeSortedArrays(int arrA[], int arrB[], int mergedArray[], int sizeA, int sizeB) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (arrA[i] <= arrB[j]) {
            mergedArray[k++] = arrA[i++];
        } else {
            mergedArray[k++] = arrB[j++];
        }
    }

    while (i < sizeA) {
        mergedArray[k++] = arrA[i++];
    }

    while (j < sizeB) {
        mergedArray[k++] = arrB[j++];
    }

}

int main() {
    int sizeA, sizeB;
    std::cout << "Enter the size of array A: ";
    std::cin >> sizeA;

    int arrA[sizeA];
    std::cout << "Enter the elements of array A in sorted order:\n";
    for (int i = 0; i < sizeA; ++i) {
        std::cin >> arrA[i];
    }

    std::cout << "Enter the size of array B: ";
    std::cin >> sizeB;

    int arrB[sizeB];
    std::cout << "Enter the elements of array B in sorted order:\n";
    for (int i = 0; i < sizeB; ++i) {
        std::cin >> arrB[i];
    }

    int mergedSize = sizeA + sizeB;
    int mergedArray[mergedSize];

    mergeSortedArrays(arrA, arrB, mergedArray, sizeA, sizeB);

    std::cout << "Merged sorted array:\n";
    for (int i = 0; i < mergedSize; ++i) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

