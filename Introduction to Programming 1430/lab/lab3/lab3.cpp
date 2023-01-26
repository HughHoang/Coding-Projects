#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");


    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(input);
    outputFile.open(output);
    int line;
    int size, timediff;
    int i = 0;
    double time_taken, time_taken2;
    inputFile >> size;
    vector<int> vec(size);
    int* arr = new int[size];
    while (!inputFile.eof()) {
        inputFile >> line;
        arr[i] = line;
        i++;
    }
    clock_t t, t1;
    t = clock();
    quickSort(arr, 0, size - 1);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    outputFile << time_taken ;

    t = clock();
    mergeSort(arr, 0, size - 1);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    outputFile <<", "<< time_taken ;

    t1 = clock();
    insertionSort(arr, size);
    t1 = clock() - t1;
    time_taken2 = ((double)t1) / CLOCKS_PER_SEC;
    outputFile << ", " << time_taken ;

    t = clock();
    selectionSort(arr, size);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    outputFile << ", " << time_taken ;

    t = clock();
    bubbleSort(arr, size);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    outputFile << ", " << time_taken ;

    outputFile.close();
    inputFile.close();
            
}

