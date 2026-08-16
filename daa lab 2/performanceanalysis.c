#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

// Linear Search
void linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key)
            break;
    }
}

// Binary Search
void binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            break;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n) {
    int min, temp;

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    int key, j;

    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Merge Sort
void merge(int a[], int low, int mid, int high) {
    int temp[N];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Copy array
void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++)
        destination[i] = source[i];
}

int main() {
    int original[N], a[N];
    int key = 500;
    clock_t start, end;
    double time_taken;

    // Generate 1000 random numbers
    srand(time(NULL));

    for (int i = 0; i < N; i++)
        original[i] = rand() % 10000;

    printf("Performance comparison for %d numbers\n\n", N);

    // Linear Search
    start = clock();
    linearSearch(original, N, key);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear Search    : %f seconds\n", time_taken);

    // For Binary Search, array must be sorted
    copyArray(original, a, N);
    quickSort(a, 0, N - 1);

    start = clock();
    binarySearch(a, N, key);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary Search    : %f seconds\n", time_taken);

    // Bubble Sort
    copyArray(original, a, N);

    start = clock();
    bubbleSort(a, N);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort      : %f seconds\n", time_taken);

    // Selection Sort
    copyArray(original, a, N);

    start = clock();
    selectionSort(a, N);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort   : %f seconds\n", time_taken);

    // Insertion Sort
    copyArray(original, a, N);

    start = clock();
    insertionSort(a, N);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort   : %f seconds\n", time_taken);

    // Merge Sort
    copyArray(original, a, N);

    start = clock();
    mergeSort(a, 0, N - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort       : %f seconds\n", time_taken);

    // Quick Sort
    copyArray(original, a, N);

    start = clock();
    quickSort(a, 0, N - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort       : %f seconds\n", time_taken);

    return 0;
}