#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int ComboCounter(int message);
int formula(int letters, int digits);

int ComboCounter(int message){
    string strMessage = to_string(message);
    int letters = 0;
    for(int i = 0; i < strMessage.length() - 1; i++){        
        string dDigits = string(1, strMessage[i]) + strMessage[i+1];
        if(stoi(dDigits) > 26){
            letters++;
        }
        else{
            letters+=2;
        }
    }
    //last letter
    letters++;
    return formula(letters, strMessage.length());
}

int formula(int letters, int digits){
    if(letters == 1){
        return 1;
    }
    //return pow(2,(((letters+1) / 2)-2)) +1;
    digits = (letters + 1) / 2;
    return pow(2, digits-2) + 1;
}

int main(){
    cout <<"There are/is " <<  ComboCounter(12713) << " different combination(s)." << endl;
    return 0;
}
