#include <iostream>
using namespace std;

void insertionSort(int nums[5], int n); // generic insertion sort algorithm
void selectionSort(int nums[5], int n); // generic selection sort algorithm

void printArray(int arr[], int n); // prints out the data of an array
void printSortData(int ci, int cic); // prints comparison and iteration data about a sort

int main()
{
    int nums[5] = {2, 5, 4, 1, 3};
    int n = 5;

    cout << endl << "Insertion Sort" << endl;
    insertionSort(nums, n);
    cout << endl << "Selection Sort" << endl;
    selectionSort(nums, n);
    
    return 0;
}

void insertionSort(int nums[], int n)
{
    int current_iteration = 0;
    int current_iteration_comparisons = 0;
    int total_comparisons = 0;
    
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while ((j >= 0) && (nums[j] > key)) {
            nums[j + 1] = nums [j];
            j = j - 1;
            current_iteration_comparisons++;
        }
        nums[j + 1] = key;
        
        current_iteration = i;
        total_comparisons = total_comparisons + current_iteration_comparisons;

        printArray(nums, n);
        printSortData(current_iteration, current_iteration_comparisons);
        cout << endl;

        current_iteration_comparisons = 0;
    }
    cout << "total comparisons: " << total_comparisons << endl;
}

void selectionSort(int nums[], int n)
{
    int current_iteration = 0;
    int current_iteration_comparisons = 0;
    int total_comparisons = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
                current_iteration_comparisons++;
            }
        }
        if (min_idx != i) {
            swap(nums[i], nums[min_idx]);
        }
        
        current_iteration = i;
        total_comparisons = total_comparisons + current_iteration_comparisons;

        printArray(nums, n);
        printSortData(current_iteration, current_iteration_comparisons);
        cout << endl;

        current_iteration_comparisons = 0;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

void printSortData(int ci, int cic) {
    cout << " | i: " << ci << " | c: " << cic;
}