#include <bits/stdc++.h>
using namespace std;
#define int long long
int mcm(int *a, int i, int j, vector<vector<int>> &siam)
{
    if (i >= j)
        return 0;
    if (siam[i][j] != -1)
        return siam[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = mcm(a, i, k, siam) + mcm(a, k + 1, j, siam) + a[i - 1] * a[k] * a[j];
        mn = min(temp, mn);
    }
    siam[i][j] = mn;
    return mn;
}
signed main()
{
    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> siam(n, vector<int>(n, -1));
    int ans = mcm(a, 1, n - 1, siam);
    cout << ans << endl;
}