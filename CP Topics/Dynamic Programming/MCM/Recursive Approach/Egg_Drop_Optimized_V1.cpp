#include <bits/stdc++.h>
using namespace std;
#define int long long

int eggdropping(int e, int f, vector<vector<int>> &siam)
{

    int m = 0;
    while (siam[m][e] < f)
    {
        m++;
        for (int k = 1; k <= e; k++)
        {
            siam[m][k] = 1 + siam[m - 1][k - 1] + siam[m - 1][k];
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<i<<" "<<siam[i][e]<<endl;
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
    vector<vector<int>> siam(f + 1, vector<int>(e + 1, 0));
    int ans = eggdropping(e, f, siam);
    cout << ans << endl;
    return 0;
}