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
vector<int>ans;
void makeSet(string s)
{
    int index = getIndexOfString(s);
    parent.push_back(index);
    ans.push_back(1);
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
        ans[u]+=ans[v];
        ans[v]=ans[u];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        parent.push_back(0);
        ans.push_back(0);
        int n;
        cin >> n;

        int i;

        for (i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            makeUnion(a, b);
            int i = getIndexOfString(a), j = getIndexOfString(b);
            parent[i]=findParent(i);
            parent[j]=findParent(j);
            int x=parent[i];
            
            cout<<ans[x]<<endl;
        }

        cnt = 0;
        parent.clear();
        mp.clear();
        ans.clear();
    }
}