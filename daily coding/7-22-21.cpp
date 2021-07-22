//Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
//For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
//You can assume that the messages are decodable. For example, '001' is not allowed.

//read amount of digits
//1 2 2 1                   //digits: 4
//1, 2, 21                  //letters: 7 (1, 12, 2, 22, 2, 21, 1)
//12, 2, 1                  //5 combonations
//1, 22, 1
//12, 21
//1, 2, 2, 1

//--------------------------
//|digits|letters|answer|
//|   1  |  1    |   1  |
//|   2  |  3    |   2  |
//|   3  |  5    |   3  |
//|   4  |  7    |   5  |
//|   5  |  9    |   9  |
//|   6  |  11   |   17 |

//--------------------------

//formula: 2^(#digits-2) +1
//digits = ((letters+1) / 2)
//plug in digits into 
//formula: 2^(((letters+1) / 2)-2) +1

//validate if letter > 26 and count #letters
//when end of string, plug into formula

//1 2 7 1 3
//12, 7, 1, 3
//1, 27, 1, 3       //invalid
//12, 71, 3         //invalid
//1, 2, 7, 1, 3
//12, 7, 13
//1, 27, 13         //invalid
//12, 71, 3         //invalid
//1, 2, 7, 13
//1, 2, 7, 1, 3


#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int ComboCounter(int message);
int formula(int letters);

int ComboCounter(int message){
    string strMessage = to_string(message);
    int letters = 0;
    for(int i = 0; i < strMessage.length() - 1; i++){        
        string dDigits = string(1, strMessage[i]) + strMessage[i+1];
        cout << dDigits << endl;
        if(stoi(dDigits) > 26){
            letters +1;
        }
        else{
            letters+=2;
        }
    }
    //last letter
    letters++;
    cout << "letters: " << letters << endl;
    return formula(letters);
}

int formula(int letters){
    if(letters == 1){
        return 1;
    }
    return pow(2,(((letters+1) / 2)-2)) +1;
}

int main(){
    cout << ComboCounter(133211) << endl;
    return 0;
}
