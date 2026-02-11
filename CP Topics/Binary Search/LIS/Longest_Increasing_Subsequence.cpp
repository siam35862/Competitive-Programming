#include <bits/stdc++.h>
using namespace std;
#define int long long
// only length
int binary_search(int n, vector<int> &a, int val)
{
    int l = 0, r = n - 1;
    int ans = r;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] > val)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}
int lis(int *a, int n)
{
    int i;
    vector<int> v;
    int ans = 0;
    v.push_back(a[0]);
    ans = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] >= v[ans - 1])
        {
            v.push_back(a[i]);
            ans++;
        }
        else
        {
            int ind = binary_search(ans, v, a[i]);
            v[ind] = a[i];
        }
    }
    return ans;
}
int32_t main()
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
        int ans = lis(a, n);
        cout<<ans<<endl;
    }
}