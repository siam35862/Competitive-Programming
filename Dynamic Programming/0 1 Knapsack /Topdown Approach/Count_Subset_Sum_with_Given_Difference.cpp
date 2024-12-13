#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
    n * s must be less than or equal 1e8
*/
vector<vector<int>> siam;
int countSubsetSum(int n, int s, int *a)
{
    int i, j;
    for (i = 0; i <= n; i++)
        siam[i][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= s; j++)
        {
            if (a[i - 1] <= j)
                siam[i][j] = siam[i - 1][j] + siam[i - 1][j - a[i - 1]];
            else
                siam[i][j] = siam[i - 1][j];
        }
    }
    return siam[n][s];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    int sum = 0;
    int a[n], i;
    for (i = 0; i < n; i++)

    {
        cin >> a[i];
        sum += a[i];
    }
    if ((s + sum) % 2 == 1)
        cout << 0 << endl;
    else
    {
        s = (s + sum) / 2;
        siam.resize(n + 1);
        for (i = 0; i <= n; i++)
            siam[i].resize(s + 1, 0);
        int ans = countSubsetSum(n, s, a);
        cout << ans << endl;
    }
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/