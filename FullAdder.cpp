#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<string>
using namespace std;


int main() {
    map< char, int> numof;
    vector<char>result;
    int base,big,small, i, len1, len2,len3;
    int carry = 0;
    char c;
    string op1, op2, alfabet, op3, lines,quastion;

    cin >> base >>alfabet;
    
    
    for (int i = 0; i < base; i++)
        numof.insert({ alfabet[i], i });

    cin >> op1 >> c >> op2;
    cin >> lines >> quastion;

    len1 = op1.length()-1;
    len2 = op2.length()-1;
    small = min(len1,len2)+1;
    big = max(len1, len2)+1;
    
    for (i = small; i > 0; i--) {
        if ((numof[op1[len1]] + numof[op2[len2]]) + carry< base)
        {
            result.push_back(alfabet[numof[op1[len1--]] + numof[op2[len2--]]+carry]);
            carry = 0;
        }
        else {
            result.push_back(alfabet[numof[op1[len1--]] + numof[op2[len2--]] + carry - base]);
            carry = 1;
        }
    }
    op3 = len1 > len2 ? op1 : op2;
    len3 = len1 > len2 ? len1 : len2;
    
    
    for (i = big - small; i > 0; i--) {
        if (numof[op3[len3]] + carry < base)
        {
            result.push_back(alfabet[numof[op3[len3--]]+carry]);
            carry = 0;
        }
        else {
            result.push_back(alfabet[numof[op3[len3--]] + carry]);
            carry = 1;
            
        }
    }
    if (carry)
        result.push_back(alfabet[1]);

    cout << base << " " << alfabet << endl;
    if (op1.length() < op2.length()) {
        for (int j = 0; j <= big - small; j++)
            cout << " ";
        cout << op1 << endl;
        cout << c << op2 << endl;
    }
    else if (op1.length() > op2.length()) {
        cout << " " << op1 << endl;
        cout << c;
        for (int j = 0; j < big - small; j++)
            cout << " ";
        cout << op2 << endl;
    }
    cout << lines << endl;
    cout << " ";


    for(int j= result.size()-1;j>=0;j--)
        cout << result[j];
    

    return 0;
}
