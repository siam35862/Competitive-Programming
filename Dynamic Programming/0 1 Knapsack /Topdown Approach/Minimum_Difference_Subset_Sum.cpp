#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
    n * sum of array must be less than or equal 1e8
*/
vector<vector<bool>> siam;
int minDiffSubsetSum(int n, int s, int *a, int sum)
{
    int i, j;
    int ans = INT_MAX;
    for (i = 0; i <= n; i++)
        siam[i][0] = true;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= s; j++)
        {
            if (a[i - 1] <= j)
                siam[i][j] = siam[i - 1][j] || siam[i - 1][j - a[i - 1]];
            else
                siam[i][j] = siam[i - 1][j];
            if (i == n && siam[i][j] == true)
            {
                ans = min(ans, sum - 2 * j);
            }
        }
    }
    return ans;
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
    siam.resize(n + 1);
    for (i = 0; i <= n; i++)
        siam[i].resize(s + 1, 0);
    int ans = minDiffSubsetSum(n, s / 2, a, s);
    cout << ans << endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/