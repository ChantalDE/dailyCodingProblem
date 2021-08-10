#include "mergeSort.h"

int main(){
    const int size = 5;
    int input[] = {4, 2, 5, 2, 1};
    //[0, 1, 2, 1, 3]
    int sorted[size];
    int output[size];

   int index = 0;
   int k = 0;
    for(int i = size-1, j = 0; i >= 0; i--, j++){
        sorted[j] = input[i];
        mergeSort(sorted, 0, j, j+1);
        for(; k < j; k++){
            cout << "input: " <<  input[i + 1] << endl;
            cout << "sorted: " << sorted[k] << endl;
            if(input[i + 1] == sorted[k]){
                cout << "match: " << endl;
                cout << "k: " << k << endl;
                output[index] = k;
                index++;
                k = 0;
                break;
            }
        }
    }
    for(int i = 0; i< size; i++){
        cout << output[i] << ", ";
    }
    return 0;
}