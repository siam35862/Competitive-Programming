#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int cnt = 0;
int getIndexOfString(string s)
{
    if (mp[s] == 0)
    {
        mp[s] = ++cnt;
    }
    return mp[s];
}
vector<int> parent;
void makeSet(string s)
{
    int index = getIndexOfString(s);
    parent.push_back(index);
}
int findParent(int c)
{

    if (c == parent[c])
        return c;
    else
        return parent[c] = findParent(parent[c]);
}
void makeUnion(string a, string b)
{

    int i = getIndexOfString(a), j = getIndexOfString(b);
    if (i >= parent.size()) // a is not exist in parent
    {
        makeSet(a);
    }
    if (j >= parent.size()) // b is not exist in parent
    {
        makeSet(b);
    }
    int u = findParent(i);
    int v = findParent(j);
    if (u != v)
    {
        parent[u] = v;
        parent[v]=v;
    }
}

int main()
{

    while (true)
    {
        parent.push_back(0);
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        int i;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            makeSet(s);
        }
        for (i = 0; i < m; i++)
        {
            string a, b;
            cin >> a >> b;
            makeUnion(a, b);
        }
        int frq[n + 1]={};
        for (i = 1; i <= n; i++)
        {
            parent[i] = findParent(i);
            frq[parent[i]]++;
        }
        int mx=0;
        for(i=1;i<=n;i++)
        {
            mx=max(mx,frq[i]);
        }
        cout<<mx<<endl;
        cnt=0;
        parent.clear();
        mp.clear();

    }
}