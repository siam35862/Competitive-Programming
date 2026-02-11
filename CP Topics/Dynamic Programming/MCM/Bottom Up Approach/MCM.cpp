#include <bits/stdc++.h>
using namespace std;
int mcm(vector<int> &a)
{
    int n = a.size();
    
    int siam[n][n]={};

    int i, j, k;
    
    int len;
    for (len = 2; len <n; len++)
    {
        for (i = 0, j = i + len; j < n; j++, i++)
        {

            siam[i][j] = INT_MAX;
            for (k = i+1; k < j; k++)
            {
               
                siam[i][j] = min(siam[i][j], a[i]*a[j]*a[k] + siam[i][k] + siam[k][j]);
            }
        }
    }
    
  
    return siam[0][n - 1];
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int i;
    for (i = 0; i < n; i++)
        cin >> a[i];
        
    int ans = mcm(a);
    cout << ans << endl;
}