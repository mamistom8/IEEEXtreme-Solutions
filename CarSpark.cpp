#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm> 
#include <utility>
using namespace std;

int Compute_Opt(int n, int* v, int* p, int * m);

int main() {
    int n, maxValue;
    int j;
    int t;
    cin >> t;
    int* result = new int[t];

    for (int k = 0; k < t; k++) {

        cin >> n;
        int* arr1 = new int[n];
        int* arr2 = new int[n];
        int* arr3 = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr2[i] >> arr1[i] >> arr3[i];
        }
        pair<  int, pair<int, int>>* pairs = new pair<int, pair<int, int>>[n];
        for (int i = 0; i < n; i++) {
            pairs[i].first = arr1[i]; //finish time
            pairs[i].second.first = arr2[i]; // start time
            pairs[i].second.second = arr3[i]; // amount
        }
        sort(pairs, pairs + n);
    

        int* p = new int[n+1] { 0 };
        int* m = new int[n+1] {0 };

        for (int i = n-1; i > 0; i--)
        {
            j = i - 1;
            while (j >= 0) {
                if (pairs[i].second.first >= pairs[j].first)
                {
                    p[i+1] = j+1;
                    break;
                }
                j--;
            }
        }

        for (int i = 0; i < n; i++)
            arr3[i] = pairs[i].second.second;

        maxValue = Compute_Opt(n, arr3, p, m );

        result[k] = maxValue;
        
        delete[] p;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] pairs;
    }

    for (int i = 0; i < t; i++)
        cout << result[i] << endl;

    delete[] result;
    return 0;
}


int Compute_Opt(int n, int* v, int* p,int * m) {
    m[0] = 0;
    for (int i = 1; i <= n; i++) {
        m[i] = max(v[i-1] + m[p[i]], m[i - 1]);
    }
    return m[n];
}





