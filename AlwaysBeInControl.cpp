#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool checkControl(int* data, int n, double ucl, double ucl1, double ucl2, double lcl, double lcl1, double lcl2, double sigma, double center);
void print(vector<int>s);
double avarge(vector<int>s);
double avarge(vector<double>s);
int range(vector<int>s);

int main() {
    int t, x, n, s, k = 0, numof_groupes;
    double grandavg, grandrange, UCL3, UCL1, UCL2, LCL3, LCL1, LCL2, sigma;
    const double A2[] = { 0,0,1.880,1.023,0.729,0.577,0.483,0.419,0.373,0.337,0.308 };
    int* data;
    vector<bool>res;
    vector<int>* groupes, ranges;
    vector<double>avarges;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> x >> n;

        if (x % n == 0)
            numof_groupes = x / n;
        else numof_groupes = x / n + 1;

        data = new int[10000];
        groupes = new vector<int>[numof_groupes];
        for (int i = 0; i < x; i++) {
            cin >> data[i];
        }
        for (int i = 0; i < numof_groupes; i++)
        {
            for (int j = 0; j < n; j++)
            {
                groupes[i].push_back(data[k++]);
                if (k == x)break;
            }
        }

        for (int i = 0; i < numof_groupes; i++) {
            avarges.push_back(avarge(groupes[i]));
            ranges.push_back(range(groupes[i]));
        }

        grandavg = avarge(avarges);
        grandrange = avarge(ranges);

        LCL1 = grandavg - A2[n] * grandrange / 3;
        LCL2 = grandavg - A2[n] * grandrange * 2 / 3;
        LCL3 = grandavg - A2[n] * grandrange;
        UCL1 = grandavg + A2[n] * grandrange / 3;
        UCL2 = grandavg + A2[n] * grandrange * 2 / 3;
        UCL3 = grandavg + A2[n] * grandrange;
        sigma = (UCL3 - grandavg) / 3;

        res.push_back(checkControl(data, x, UCL1, UCL2, UCL3, LCL1, LCL2, LCL3, sigma, grandavg));

        delete[] data;
        (*groupes).clear();
        avarges.clear();
        ranges.clear();
        k = 0;
    }

    for (int i = 0; i < t; i++)
    {
        if (res[i])
            cout << "In Control" << endl;
        else cout << "Out of Control" << endl;
    }
    return 0;
}


void print(vector<int>s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;

}

double avarge(vector<int>s)
{
    if (s.size() == 1)
        return s[0];
    double avg = 0;
    for (int i = 0; i < s.size(); i++)
        avg += s[i];
    return avg / s.size();
}

double avarge(vector<double>s)
{
    if (s.size() == 1)
        return s[0];
    double avg = 0;
    for (int i = 0; i < s.size(); i++)
        avg += s[i];
    return avg / s.size();
}

int range(vector<int>s) {
    if (s.size() == 1)
        return 0;
    int min = 10001, max = -10001;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < min) min = s[i];
        if (s[i] > max) max = s[i];
    }
    return max - min;
}

bool checkControl(int* data, int n, double ucl1, double ucl2, double ucl3, double lcl1, double lcl2, double lcl3, double sigma, double center)
{

    for (int i = 0; i < n; i++) {
        if (data[i] > ucl3 || data[i] < lcl3) {
            return false;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        int c2_up = 0, c2_down = 0;
        for (int j = 0; j < 3; j++) {
            if (data[i + j] > ucl2) c2_up++;
            if (data[i + j] < lcl2) c2_down++;
        }
        if (c2_up >= 2 || c2_down >= 2) {
            return false;

        }
    }
    
    for (int i = 0; i < n - 4; i++) {
        int c3_up = 0, c3_down = 0;
        for (int j = 0; j < 5; j++) {
            if (data[i + j] > ucl1) c3_up++;
            if (data[i + j] < lcl1) c3_down++;
        }
        if (c3_up >= 4 || c3_down >= 4) {
            return  false;
        }
    }
    
    for (int i = 0; i < n - 7; i++) {
        int c4_up = 0, c4_down = 0;
        for (int j = 0; j < 8; j++) {
            if (data[i + j] > center) c4_up++;
            if (data[i + j] < center) c4_down++;
        }
        if (c4_up == 8 || c4_down == 8) {
            return  false;
        }

    }


    return true;
}

