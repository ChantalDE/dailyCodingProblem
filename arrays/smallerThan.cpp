//#include <algorithm>
using namespace std;



//input: [3, 4, 8, 1, 2, 5]
//output:[2, 2, 3, 0, 0, 0]

//seen: [1, 2, 3, 4, 5, 8]

//seen:

//index placed:  [0, 0, 0, 3, 2, 2]




int* smallerThan(int* arr, int size){
    int* output = new int[size]();
    for(int i = size-1; i != 0; i--){
        output[i] = arr[i];
        sort(output, size);
    }
}

int main(){

    return 0;
}