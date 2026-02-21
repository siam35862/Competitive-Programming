#include <bits/stdc++.h>
using namespace std;
 #define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n>>x;
        int a[n];
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        int ans = 0;
        for (i = 0; i < n; i++)
            ans = max(ans, a[i] + x*i);
        cout << ans << endl;
    }
}