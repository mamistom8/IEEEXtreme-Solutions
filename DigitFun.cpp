#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int count=0;
    string A;
    vector<int> result;
    cin >> A;
    while (A != "END") {
        while (A != "1") {
            count++;
            A = to_string(A.length());
        }
        result.push_back(++count);
        count = 0;
        cin >> A;
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }




    return 0;
}
