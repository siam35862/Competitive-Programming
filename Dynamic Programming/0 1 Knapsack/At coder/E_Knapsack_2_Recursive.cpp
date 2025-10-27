#include <bits/stdc++.h>
using namespace std;
#define int long long
int siam[101][100001];

int knapsack(int n, int v, int *wt, int *val)
{

    if (v == 0)
        return 0;
    if (n == 0)
        return INT_MAX;
    if (siam[n][v] != -1)
        return siam[n][v];
    if (val[n - 1] <= v)
    {
        siam[n][v] = min(knapsack(n - 1, v, wt, val), wt[n - 1] + knapsack(n - 1, v - val[n - 1], wt, val));
    }
    else
        siam[n][v] = knapsack(n - 1, v, wt, val);

    return siam[n][v];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w;
    cin >> n >> w;
    int v = 0;
    int wt[n], val[n], i, j;
    for (i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
        v += val[i];
    }
    for (i = 0; i < 101; i++)
    {
        for (j = 0; j < 100001; j++)
            siam[i][j] = -1;
    }
    int ans = 0;
    for (i = 1; i <= v; i++)
    {
        if (knapsack(n, i, wt, val) <= w)
            ans = i;
    }
    cout << ans << endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
