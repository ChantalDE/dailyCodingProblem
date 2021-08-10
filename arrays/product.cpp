//Get the product of the array for each element, not including the element itself
#include <iostream>

using namespace std;
int* productD(int input[], int size);
int* productWD(int input[], int size);


//fucntion W/ Division
int* productD(int input[], int size){
    int product = 1;
    for (int i = 0; i < size; i++){
        product *= input[i];
    }
    int* output = new int[size]();
    for (int i = 0; i < size; i++){       
        output[i] = product / input[i];
    }
    return output;
}

//function w/o division
int* productWD(int input[], int size){
    int* output = new int[size]();
    output[0] = 1;
    int product = 1;
    for(int i = 0; i < size-1; i++){
        product *= input[i];
        output[i+1] = product;
    }
    output[size-1] = product;
    product = 1;

    for(int i = size-1; i > 0; i--){
        product *= input[i];
        output[i-1] = output[i-1] * product;
    }
    return output;
};

int main(){
    int array[] = {1, 2, 3, 4, 5};
    int size = 5;
    int* output = productD(array, size);
    for (int i = 0; i < size; i++){
    cout << output[i] << ", ";}
    cout << "\n";
 
    int* output2 = productWD(array, size);
    for (int i = 0; i < size; i++){
    cout << output2[i] << ", ";}

    return 0;
}
