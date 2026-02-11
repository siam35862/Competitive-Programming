#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    int distinct = 0;
    int ans = 0, l = 0;
    unordered_map<int, int> cntr;
    for (int r = 0; r < n; r++)
    {
        cntr[a[r]]++;
        if (cntr[a[r]] == 1)
            distinct++;
        while (distinct > k)
        {
            cntr[a[l]]--;
            if (cntr[a[l]] == 0)
                distinct--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}