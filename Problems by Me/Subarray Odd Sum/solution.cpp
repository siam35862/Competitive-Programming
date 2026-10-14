#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, i;
    cin >> n >> s;
    vector<int> a(n + 1);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int sum = 0;
    int ans = 0;
    for (r = 0; r < n; r++)
    {
        if (a[r] % 2)
            sum += a[r];
        while (sum > s)
        {
            if (a[l] % 2)
                sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;

    return 0;
}