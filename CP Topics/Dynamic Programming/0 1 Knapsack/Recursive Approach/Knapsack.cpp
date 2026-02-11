#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
time complexity: O(n*w)
n*w must be less than 1e8
*/
vector<vector<int>> siam;
int knapsack(int n, int w, int *val, int *wt)
{
    if (n == 0 || w == 0)
        return 0;
    if (siam[n][w] != -1)
        return siam[n][w];
    if (wt[n-1]<=w)
    {
        return siam[n][w]=max(val[n-1]+knapsack(n-1,w-wt[n-1],val,wt),knapsack(n-1,w,val,wt));
    }
    else return siam[n][w]=knapsack(n-1,w,val,wt);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, w;
    int i, j;
    cin >> n >> w;
    int val[n], wt[n];
    for (i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    siam.resize(n + 1);
    for (i = 0; i <= n; i++)
        siam[i].resize(w + 1, -1);
    int ans = knapsack(n, w, val, wt);
    cout << ans << endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/