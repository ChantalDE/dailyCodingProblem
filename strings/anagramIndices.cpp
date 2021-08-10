//return a list of indeces where the string inside of a word appears
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

vector <int> find(string w, string s){
    vector<int> output;
    for(int index = 0; index < w.size(); index++){
        bool found = false;
        if(w[index] == s[0]){
            int i = index;
            i++;
            for(int j = 1; j < s.size(); j++, i++){
                if(w[i] == s[j]){
                    found = true;
                }
                else{
                    found = false;
                    break;
                }
            }
        }
        if(found){
            output.push_back(index);
        }
    }

    for(int index = w.size()-1; index != 0; index--){
        bool found = false;
        if(w[index] == s[0]){
            int i = index;
            i--;
            for(int j = 1; j < s.size(); j++, i--){
                if(w[i] == s[j]){
                    found = true;
                }
                else{
                    found = false;
                    break;
                }
            }
        }
        if(found){
            output.push_back(index);
        }
    }
    return output;
}

vector <int> find2(string w, string s){
    vector<int> output;
    for(int index = 0; index < w.size(); index++){
        if(w[index] == s[0]){
            if(w.substr(index, s.size()) == s){
                output.push_back(index);
                index+=s.size();
            }
        }
    }

for(int index = w.size()-1; index != 0; index--){
        if(w[index] == s[0]){
            if(w.substr(index-s.size(), s.size()) == s){
                output.push_back(index);
                index-=s.size();
            }
        }
    }
    return output;
}

vector<int> anagramIndices(string w, string s){
    vector<int> output;
    //word or string is empty
    if(w.size() == 0 || s.size() == 0){
        return output;
    }
    map<char, int> str;
    int stringSum = 0;
    //load in
    for(int i = 0; i < s.size(); i++){
        stringSum+= s[i];
        if(str.find(s[i])->first == s[i]){
            str.find(s[i])->second++;
        }
        else{
            str.emplace(s[i], 1);
        }
    }

//abxaba  ab
//left: 1
//right: 2

    int left = 0;
    int right = s.size() -1;
    map<char, int> checkAnagram = str;
    while(left < w.size()){
        cout << left << "\t" << right << endl;
        if(str.find(w[left])!= str.end() && str.find(w[left])->second != 0) str.find(w[left])->second--;
        else right++;
        if(left == right){
            output.push_back(right-s.size()+1);
            str = checkAnagram;
            right+=s.size();
            if(right > w.size() -1) right = w.size() -1;
        }
        left++;
    }
    // vector<int> output;
    // for(int i = 0; i < w.size(); i++){
    //     map<char, int> checkAnagram = str;
    //     int counter = 0;
    //     for(int j = 0; j < s.size() && i+j < w.size(); j++){
    //         if(checkAnagram.find(w[i+j]) == checkAnagram.end() || checkAnagram.find(w[i+j])->second == 0){
    //             break;
    //         }
    //         else{
    //             checkAnagram.find(w[i+j])->second--;
    //             counter++;
    //         }
    //     }
    //     if(counter == s.size()){
    //         output.push_back(i);
    //     }
    // }
    return output;
}


int main(){
    string word = "abxaba";
    string str = "ab";
    vector<int> output = anagramIndices(word, str);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << ", ";
    }
    return 0;
}


