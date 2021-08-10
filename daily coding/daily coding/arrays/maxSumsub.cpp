#include <iostream>
using namespace std;

//Kadane Algorithm
//input: [-1, 10, 3, -6, 100, -1, 2]
//answer: [-1, 10, 3, -6, 100, -1, 2]


int* maxSubArray(int* arr, int size, int &subSize);

int* maxSubArray(int* arr, int size, int &subSize){
    int begin = 0;
    int end = 0;
    int maxSumNow = 0;
    int trackerSum = 0;
    for(int i = 0; i < size; i++){
        trackerSum += arr[i];
        if(trackerSum > maxSumNow){
            maxSumNow = trackerSum;
            end = i;
        }
        if(trackerSum < 0){
            trackerSum = 0;
            begin = i + 1;
        }
    }
    subSize = end-begin + 1;
    int* subArr = new int[subSize]();
    for(int i = begin, j = 0; i != end + 1; i++, j++){
        subArr[j] = arr[i];
    }
    return subArr;
}

int main(){
    int size = 7;
    int subSize = 0;
    int input[] =  {-1, 10, 3, -6, 100, -1, 2};
    int* output = maxSubArray(input, size, subSize);
    for(int i = 0; i < subSize; i++){
        cout << output[i] << ", ";
    }
    return 0;
}