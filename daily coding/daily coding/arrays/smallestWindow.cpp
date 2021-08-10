#include <iostream>
#include <utility>
using namespace std;

void swap(int sorted[], int i);
int* sort(int arr[], int size);
pair<int, int> window(int arr[], int sorted[], int size);

void swap(int sorted[], int i){
    int temp = sorted[i];
    sorted[i] = sorted[i+1];
    sorted[i+1] = temp;
    if(i-1 == -1){
        return;
    }
    if(sorted[i] < sorted[i-1]){
        swap(sorted, i-1);
    }
}

pair<int, int> window(int arr[], int sorted[], int size){
    int left = 0;
    int right = 0;
    int j = size -1;
    bool lSet = false;
    bool rSet = false;
    for(int i = 0; (i < size || left == 0) && (j == 0 ||right == 0); i++, j--){
        cout << "hello?" << endl;
        if(arr[i] != sorted[i] && lSet == false){
            left = i;
            lSet = true;
        }
        if(arr[j] != sorted[j] && rSet == false){
            right = j;
            rSet = true;
        }
    }
    pair<int, int> output;
    output.first = left;
    output.second = right;
    return output;
}

int* sort(int arr[], int size){
    int* sorted = new int[size]();
    for(int i = 0 ; i < size; i++){
        sorted[i] = arr[i];
    }
    for(int i = 0; i < size-1; i++){
        if(sorted[i+1] < sorted[i]){
            swap(sorted, i);
        }
    }
    return sorted;
}

int main(){
    int size = 5;
    int arr[] = {3, 7, 5, 6, 9};
    int* sorted = sort(arr, size);

    pair<int, int> output = window(arr, sorted, size);
    cout << output.first << ", " << output.second;
    return 0;
}