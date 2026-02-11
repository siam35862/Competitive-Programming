#include <bits/stdc++.h>
using namespace std;
#define int long long

int eggdropping(int e, int f)
{
    vector<int> siam(e + 1, 0);
    int m = 0;
    while (siam[e] < f)
    {
        m++;
        for (int k = e; k > 0; k--)
        {
            siam[k] += (1 + siam[k - 1]);
        }
    }
    return m;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e, f;
    cin >> e >> f;
    int ans = eggdropping(e, f);
    cout << ans << endl;
    return 0;
}