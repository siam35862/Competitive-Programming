#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], c[n], p[n] = {};
        int maxA = 0, maxB = 0, maxC = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            maxA = max(maxA, a[i]);
            maxB = max(maxB, b[i]);
            maxC = max(maxC, c[i]);
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] >= maxA)
                p[i]++;
            if (b[i] >= maxB)
                p[i]++;
            if (c[i] >= maxC)
                p[i]++;
        }
        int ans = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i] == 3)
                ans++;
        }
        if (ans == 0)
        {
            for (i = 0; i < n; i++)
            {
                if (p[i] == 2)
                    ans++;
            }
        }
        if (ans == 0)
        {
            for (i = 0; i < n; i++)
            {
                if (p[i] == 1)
                    ans++;
            }
        }
        if (ans == 0)
            ans = n;
        cout << n << endl;
    }
}