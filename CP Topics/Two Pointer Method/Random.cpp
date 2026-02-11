#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;
        int alice = 0, bob = 0, l = 0, r = n - 1;
        while (l <= r)
        {
            if (alice == bob)
            {
                ans = max(ans, l + n - r - 1);

                if (l < n)
                {
                    alice += a[l];
                    l++;
                }
                else break;
                if (r >= 0)
                {
                    bob += a[r];
                    r--;
                }
                else break;
            }
            if (alice < bob)
            {
                alice += a[l];
                l++;
            }

            if (bob < alice)
            {
                bob += a[r];
                r--;
            }
            if (alice == bob)
            {
                ans = max(ans, l + n - r - 1);

                if (l < n)
                {
                    alice += a[l];
                    l++;
                }
                else break;
                if (r >= 0)
                {
                    bob += a[r];
                    r--;
                }
                else break;
            }
         //   cout << alice << " " << bob << endl;
        }

        cout << ans << endl;
    }
}