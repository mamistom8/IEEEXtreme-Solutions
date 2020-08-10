#include <iostream>
#include <istream>
using namespace std;

void change(int*& seq,int i);
void query(int* &seq, int n);

int main() {
	int n, * seq, c ,p;
	cin >> n;
	seq = new int[n] {0};
	query(seq, n);
	cin >> p;
	for (int i = 0; i < n; i++) {
		change(seq,i);
		query(seq, n);
		cin >> c;
		if (c == n)
			break;
		if (c <= p)
		change(seq,i);
		p = c;
	}
	cout << "A";
	for (int i = 0; i < n; i++) {
		cout << " " << seq[i];
	}
	cout << endl;
	cout.flush();	
}

void change(int* &seq, int i)
{
	if (seq[i] == 0)
		seq[i] = 1;
	else seq[i] = 0;
}

void query(int* &seq,int n) {
	cout << "Q";
	for (int i = 0; i < n; i++) {
		cout << " " << seq[i];
	}
	cout << endl;
	cout.flush();
}
