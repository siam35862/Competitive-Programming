#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back()
#define tp top()
#define pp pop()
#define fr front()
#define pf push_front
#define pfb pop_front()
#define beg begin()
#define end end()
#define rbeg rbegin()
#define rend rend()
#define sz size()
#define len length()
#define endl '\n'
#define srt(v) sort(v.beg, v.end)
#define M 1000000007
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> visited;
vector<int> cycle;
vector<int>path;
void cycleDetect(int ind, int *a, int n)
{
    if (visited[ind] == 2)
        return;
    visited[ind] = 1;
    if (visited[a[ind]] == 0)
        cycleDetect(a[ind], a, n);
    else if (visited[a[ind]] == 1)
    {
        int val = a[ind];
        cycle[val]=1;
        visited[val]=2;
        ind=a[ind];
       
        while (a[ind] != val)
        {
            cycle[ind] = 1;
            visited[ind]=2;
            ind = a[ind]; 
            cycle[ind]=1;  
            visited[ind]=2;
           
        }
        visited[ind] = 2;
        return;
    }
    visited[ind] = 2;
}
int longestpath(int ind,int *a)
{
    if(cycle[ind]==1)return path[ind]=0;
    if(path[ind]!=-1)return path[ind];
    return path[ind]=1+longestpath(a[ind],a);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n + 1];
        for (i = 1; i <= n; i++)
            cin >> a[i];

        visited.resize(n + 1);
        cycle.resize(n + 1);
        path.resize(n+1);
        for (i = 0; i <= n; i++)
        {
            visited[i] = 0;
            cycle[i] = 0;
            path[i]=-1;
        }
        for (i = 1; i <= n; i++)
        {
            cycleDetect(i, a, n);
        }
       
        int ans = 0;
       // cout<<cycle[2]<<endl;
        for (i = 1; i <= n; i++)
        {
            int cnt = longestpath(i,a);
           
            ans = max(ans, cnt);
        }
        cout << ans + 2 << endl;
    }
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/