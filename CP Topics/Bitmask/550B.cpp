#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    int a[n];
    int k;
    for (k = 0; k < n; k++)
    {
        cin >> a[k];
    }
    int mask = 0, ans = 0;
    for (mask = 0; mask < (1 << n); mask++)
    {
        vector<int> v;
        int i;
        long long s = 0;
        for (i = 0; i < n; i++)
        {
            if ((mask & (1 << i)))
            {
                v.push_back(a[i]);
                s += a[i];
            }
        }
       
        int len = v.size();
       
        sort(v.begin(), v.end());
        
        if (len>=2&&((v[len-1]-v[0])>=x) && s >= l && s <= r)
        {
            ans++;
           // cout << s << endl;
        }
        v.clear();
    }
    cout << ans << endl;
}