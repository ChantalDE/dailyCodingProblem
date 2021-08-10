#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
using namespace std;

void mergeSort(int arr[], int begin, int end, int size);
void merge(int arr[], int begin, int mid, int end, int size);

void mergeSort(int arr[], int begin, int end, int size){
//base case
    if(begin >= end){
        return;
    }
//left side
    int mid = (end+begin)/2;
    mergeSort(arr, begin, mid, size);
    mergeSort(arr, mid+1, end, size);

//merge
   merge(arr, begin, mid, end, size);
}

void merge(int arr[], int begin, int mid, int end, int size){
    int* output = new int[end-begin]();
//left side

    int i = begin;
    int j = mid+1;
    int outIndex = 0;
    //int index;
    while(i < mid+1 && j < end+1){
        if(arr[i] > arr[j]){
            output[outIndex] = arr[j];
            j++;
        }
        else{
            output[outIndex] = arr[i];
            i++;
        }
        outIndex++;
    }
//fill rest of A
    while(i < mid+1){
        for(; i < mid+1; i++, outIndex++){
            output[outIndex] = arr[i];
        }
    }
//fill rest of B
    while(j < end+1){
        for(; j < end+1; j++, outIndex++){
            output[outIndex] = arr[j];
        }
    }
    for(int i = 0; i < outIndex; ++i,++begin){
        arr[begin] = output[i];
    }
    for(int i = 0; i < size; ++i){
        cout << arr[i] << ", ";
    }
    cout << "\n";
    delete[] output;
}

#endif
