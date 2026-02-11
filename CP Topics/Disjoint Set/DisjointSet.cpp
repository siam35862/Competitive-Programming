#include <bits/stdc++.h>
using namespace std;
int parent[200005];
void makeSet(int n)
{
    parent[n] = n;
}
int findParent(int c)
{
    if (c == parent[c])
        return c;
    else
        return parent[c] = findParent(parent[c]);
}
void makefriend(int a, int b)
{
    int u = findParent(a);
    int v = findParent(b);
    if (u != v)
    {
        parent[u] = v;
    }
}

int main()
{
    cout << "Enter the number of person: ";
    int n;
    cin >> n;
    int i;
    char ch;
    cout << "Enter the perons (one letter consider as a person ):\n";
    for (i = 0; i < n; i++)
    {
        cin >> ch;
        makeSet(ch);
    }
    cout << "Enter query number: ";
    int q;
    cin >> q;
    cout << "Enter  0 for making friendship between two person,\n";
    cout << " 1 for finding friendship between two person\n";
    while (q--)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;
        if (a == 0)
        {
            makefriend(s[0], s[1]);
        }
        else
        {
            int b = findParent(s[0]);
            int c = findParent(s[1]);
            if (b == c)
                cout << "They are friend.\n";
            else
                cout << "They are not friend.\n";
        }
    }
}