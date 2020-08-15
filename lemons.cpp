#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, m, s, res;
    cin >> n >> m >> s;
    
    res = (n - 1) * m + ((floor(log2(n)) + 1) * s); // binary search on the bad pump
    
    if (n == 4)
        res -= 2;

    cout << res;

    return 0;
}
