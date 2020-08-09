#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    map< int, vector<string>, less< int >> mymap;
    int n, h, pos=1;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str>> h ;
        mymap[h].push_back(str);
        
    }
    for (auto itr = mymap.begin(); itr != mymap.end(); itr++) {
        sort(itr->second.begin(), itr->second.end());
        for (auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++) {
            cout << *vitr << " ";
            
        }
        if (itr->second.size() == 1)
            cout << pos <<" " << pos;
        else
         cout << pos << " " << pos+itr->second.size()-1;
        pos += itr->second.size();
        cout << endl;
    }

    return 0;
}



