#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;
void setWordToNum(map<string, int>& wordToNum);
void toDecimal(vector<long long>& sums);


int main() {
    int N;
    long long result= 1,sum=0;
    map<string, int> wordToNum;
    setWordToNum(wordToNum);
    vector<string> words,sentances;
    vector <long long> sums;
    string s,d=" ",word;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        while (s.find(d) != s.npos)
        {
            word = s.substr(0, s.find(d));
            words.push_back(word);
            s.erase(0, s.find(d) + 1);
        }
        words.push_back(s);

        for (int i = 0; i < words.size(); i++)
        {
            sum = sum * 10 + wordToNum[words[i]];
        }
        words.clear();
        sums.push_back(sum);
        sum = 0;
    
    }
    toDecimal(sums);
    for (int i = 0; i < N; i++)
        result *= sums[i];
    cout << result;
    
   
    
    return 0;
}

void setWordToNum(map<string, int> &wordToNum) {
    wordToNum["xrtp"] = 0;
    wordToNum["pmr"] = 1;
    wordToNum["yep"] = 2;
    wordToNum["yjtrr"] = 3;
    wordToNum["gpit"] = 4;
    wordToNum["gobr"] = 5;
    wordToNum["doc"] = 6;
    wordToNum["drbrm"] = 7;
    wordToNum["rohjy"] = 8;
    wordToNum["momr"] = 9;

}


void toDecimal(vector<long long>& sums) {
    stringstream ss;
    for (int i = 0; i < sums.size(); i++)
    {
        ss << to_string(sums[i]);
        ss >> hex >> sums[i];
        ss.clear();
    }
       
}

