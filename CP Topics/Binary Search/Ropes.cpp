#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d double

int n, k;

bool isitfit(int *a, d r)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        c += (a[i] / r);
    }
    return c >= k;
}
d solve(int *a, d l)
{
    d r = 1e7;
    d mid;
    while (r - l >pow(10,-6))
    {
        mid = l + (r - l) / 2;
        // cout<<mid<<endl;
        if (isitfit(a, mid) == false)
            r = mid;
        else
            l = mid;
    }
    return l;
}
signed main()
{

    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    d l = 0;

    d ans = solve(a, l);
    cout <<fixed<<setprecision(10)<< ans << endl;
}