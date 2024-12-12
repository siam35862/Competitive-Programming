#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int s = 0;
    int a[n+1], i;
    for (i = 1; i <=n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    int siam[n+1][s+1]={};
    for(i=1;i<=n;i++)
    {
        int j;
        for(j=1;j<=s;j++)
        {
            if(a[i]<=j)
            {
                siam[i][j]=max(siam[i-1][j],a[i]+siam[i-1][j-a[i]]);

            }
            else siam[i][j]=siam[i-1][j];
        }
    }
    set<int>st;
    for(i=1;i<=s;i++)
    {
        if(siam[n][i]>0)st.insert(siam[n][i]);
        
    }
    cout<<st.size()<<endl;
    for(auto it:st)cout<<it<<" ";
    cout<<endl;


}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/

// time complexity O(n * sum of array)
