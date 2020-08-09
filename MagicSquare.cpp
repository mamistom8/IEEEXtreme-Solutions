#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mainDiagonal(int** square, int N);
void columnsCheck(int** squre, int N, int main,vector<int> &v);
void antiCheck(int** squre, int N, int main,vector<int> &v);
void rowCheck(int** squre, int N, int main,vector<int> &v);

int main() {
    int N;
    int main = 0;
    vector<int > v;
    cin >> N;
    int** square = new int* [N];
    for (int i = 0; i < N; ++i)
        square[i] = new int[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> square[i][j];

    main = mainDiagonal(square,N);

    columnsCheck(square, N, main,v);
    antiCheck(square, N, main,v);
    rowCheck(square, N, main,v);

    
    cout << v.size()<<endl;
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    cout << *i << endl;
    
    return 0;
}


int mainDiagonal(int** square,int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) 
        sum += square[i][i];
    return sum;
}

void columnsCheck(int** squre, int N,int main,vector<int> &v) {
    int colSum = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            colSum += squre[j][i];
        }
        if (colSum != main)
        {
            v.push_back(-(i+1));
        }
        colSum = 0;
    }
}


void antiCheck(int** squre, int N, int main,vector<int> &v) {
    int sum=0;
    for (int i = 0, j = N-1; i < N; i++, j--) {
        sum += squre[i][j];
    }
    if (sum != main)
    {
        v.push_back(0);
    }
}


void rowCheck(int** squre, int N, int main,vector<int> &v) {
    int rowSum = 0;
    for (int i = 0; i <N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            rowSum += squre[i][j];
        }
        if (rowSum != main)
        {
            v.push_back(i+1);
        }
        rowSum = 0;
    }
}
