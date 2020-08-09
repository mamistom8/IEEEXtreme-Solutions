#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define whight first;


int main() {
	int t,c, n, *w, *p,**mat;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> c >> n;
		w = new int[n];
		p = new int[n];
		mat = new int* [n + 1];
		mat[0] = new int[c + 1]{ 0 };
		for (int i = 1; i <= n; i++)
		{
			mat[i] = new int[c + 1];
		}
		for (int i = 0; i <= n; i++)
		{
			mat[i][0] = 0;
		}

		for (int i = 0; i < n; i++) {
			cin >> w[i + 1] >> p[i + 1];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (j < w[i]) {
					mat[i][j] = mat[i - 1][j];
				}
				else {
					mat[i][j] = max(p[i] + mat[i - 1][j - w[i]], mat[i - 1][j]);
				}
			}
		}

		cout << mat[n][c]<<endl;
	}
	return 0;
}
