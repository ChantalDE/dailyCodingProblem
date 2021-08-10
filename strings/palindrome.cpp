//check if a list of strings are palidromes to eachother, and return the list of pairs.

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
//input: [code, edoc, da, d]
//output: (0,1), (1,0), (2,3)

string returnMapKey(string input);
vector<pair<int, int>> solution(vector<string> input);
void palindromePair(string str, map<string, pair<string, int>> &paliMap, int &i, vector<pair<int, int>> &output);

vector<pair<int, int>> solution(vector<string> input){
    vector<pair<int, int>> output;
    map<string, pair<string, int>> paliMap;
    for(int i = 0; i < input.size(); i++){
        pair <string, int> mapVal;
        mapVal.first = input[i];
        mapVal.second = i;
        paliMap.emplace(returnMapKey(input[i]), mapVal);
    }
    //push palindromes
    for(int i = 0; i < input.size(); i++){
        palindromePair(input[i], paliMap, i, output);
    }
    return output;
}

void palindromePair(string str, map<string, pair<string, int>> &paliMap, int &j, vector<pair<int, int>> &vecOutput){
    string preFix = "";
    string postFix = str;
    for(int i = 0; i < str.size(); i++){
        preFix += postFix[0];
        postFix = postFix.substr(1, postFix.size()-1);
        cout << "preFix: " << preFix << "\t postFix: " << postFix << endl;
        pair<int, int> output;
        if(paliMap.find(preFix) != paliMap.end() && j != paliMap.find(preFix)->second.second){
            cout << "HAS PREFIX" << endl;
            output.first = j;
            output.second = paliMap.find(preFix)->second.second;
            vecOutput.push_back(output);
        }
        if(paliMap.find(postFix) != paliMap.end() && j != paliMap.find(postFix)->second.second){
            cout << "HAS POSTFIX" << endl;
            output.first = paliMap.find(preFix)->second.second;
            output.second = j;
            vecOutput.push_back(output);
        }
    }
}
string returnMapKey(string input){
    if(input.size() == 0 || input.size() ==1){
        return input;
    }
    reverse(input.begin(), input.end());
    return input;
}

int main(){
    vector<string> input = {"maaaaar", "am", "da", "d"};
    vector<pair<int, int>> output = solution(input);

    cout << "output: " << endl;
    for(int i = 0; i < output.size(); i++){
        cout << "("<< output[i].first << ", " << output[i].second << "), ";
    }
    return 0;
}




