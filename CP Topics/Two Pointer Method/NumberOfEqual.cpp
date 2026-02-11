#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, m;
    cin >> n >> m;

    int a[n], b[m], i, j;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];

    j = 0;
    i = 0;
    int ans = 0;
    int frqa = 0;
    int f = 0;
    int vala=a[0];
    while (i < n || j < m)
    {
        if (j == m || (i < n && a[i] <= b[j]))
        {
            if (f == 0)
            {
                frqa = 0;
                f = 1;
            }
            vala=a[i];
            if (a[i] == b[j])
                frqa++;
            else
                frqa = 0;

            i++;
        }
        else
        {
            f = 0;
            
            if(b[j]==vala)ans += frqa;
            j++;
        }
    }
    cout << ans << endl;
}