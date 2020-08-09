#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include<vector>
using namespace std;

int main() {

    set< long long >::reverse_iterator itr;
    vector<long long> res;
    set<long long>small_route, big_route;
    long long a, b, q, big, small, tmp;
    int aLevel, bLevel,lowlevel,biglevel, distance, n, j = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (a != b)
        {
        aLevel = log2(a);
        bLevel = log2(b);
        distance = aLevel + bLevel;
        big = max(a, b) >> 1;
        small = min(a, b);
        
            while (small > 0)
            {
                small_route.insert(small);
                small = small >> 1;
            }
            while (big > 0)
            {
                //big_route.insert(big);
                if(small_route.find(big)!=small_route.end())
                { 
                    n = log2(big);
                    distance -= n * 2;
                    break;
                }
                big = big >> 1;

            }
           
            res.push_back(distance);
        }
        else(res.push_back(0));

        big_route.clear();
        small_route.clear();
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}

