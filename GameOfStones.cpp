#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string checkWinner(vector <int> games[], int g);

int main() {
    int t, g, piles, stones;
    vector <int>* games=NULL;
    vector<string> res;
    cin >> t;
    for (int k = 0; k < t; k++) 
    {
        cin >> g;
        games = new vector<int>[g];
        for (int i = 0; i < g; i++)
        {
            cin >> piles;
            for (int j = 0; j < piles; j++)
            {
                cin >> stones;
                games[i].push_back(stones/2);
            }
        }
        res.push_back(checkWinner(games, g));
        games->clear();
    }

    for (int i = 0; i < t; i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}


string checkWinner(vector <int> games[],int g) {
    //alice turn = 0 || bob turn = 1
    int sum = 0;
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < games[i].size(); j++) {
            sum += games[i][j];
        }
    }
    return sum % 2 == 0 ? "Bob" : "Alice";
}
