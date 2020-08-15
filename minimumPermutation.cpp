#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void printList(list<int> A);

int main() {
    int n,m,*arr,*S,num,i;
    
    
    list<int> A;
    list<int>::iterator it = A.begin();
    cin >> n >> m;
    S = new int[m];
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> S[i];
        
    }
    A.insert(A.begin(), arr, arr + n);
    it = A.begin();
    sort(S, S+m);
    i = 0;
    for (it = A.begin(); it != A.end(); ++it)
    {
        while (S[i] < *it && i<m)
        {
            A.insert(it, S[i++]);
        }
    }
    if (i < m)
    {
        for (i; i < m; i++)
        {
            A.push_back(S[i]);
        }
    }


    printList(A);


    
    return 0;
}

void printList(list<int> A)
{
    list<int>::iterator itr = A.begin();
    for (itr = A.begin(); itr != A.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

