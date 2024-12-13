#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
    n * sum of array must be less than or equal 1e8
*/
vector<vector<int>> siam;
int ans = INT_MAX, sum = 0, m;
bool minDiffSubsetSum(int n, int s, int *a)
{
    if (s == 0)
        return true;
    if (n == 0)
        return false;
    if (siam[n][s] != -1)
        return siam[n][s];
    if (a[n - 1] <= s)
    {
        siam[n][s] = max(minDiffSubsetSum(n - 1, s, a), minDiffSubsetSum(n - 1, s - a[n - 1], a));
    }
    else
        siam[n][s] = minDiffSubsetSum(n - 1, s, a);
    if (n == m && siam[n][s] == 1)
        ans = min(ans, sum - 2 * s);
    return siam[n][s];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s = 0;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    sum = s;
    m = n;
    s /= 2;
    siam.resize(n + 1);
    for (i = 0; i <= n; i++)
        siam[i].resize(s + 1, -1);
    minDiffSubsetSum(n, s, a);
    cout << ans << endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/