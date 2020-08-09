#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int find(int a[], int n, int k);

int main() {
    int t, K, N;
    int* a;
    cin >> t;
    vector<int> results;
    for (int i = 0; i < t; i++) {
        cin >> N >> K;
        a = new int[N];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        sort(a, a + N);
    results.push_back(find(a, N, K));
    }

    for (int i = 0; i < t; i++) {
        cout << results[i] << endl;
    }
   
    return 0;
}

int find(int a[], int n, int k)
{
    vector<int> v;

    for (int i = 1; i < n; ++i) {
        v.push_back(a[i - 1] - a[i]);
    }

    sort(v.begin(), v.end());

    int res = a[n - 1] - a[0];
 
    for (int i = 0; i < k - 1; ++i) {
        res += v[i];
    }

    return res;
}

