#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int prefixsum[n + 1][41]={};
        int i;
        for (i = 0; i < 41; i++)
        {
            prefixsum[0][i] = 0;
        }
        for (i = 1; i <= n; i++)
        {
            int v;
            cin >> v;
            for(int j=1;j<=40;j++)
            {
                prefixsum[i][j]=prefixsum[i-1][j];
            }
            prefixsum[i][v]++;
        }
        
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            int prefix[41] = {};
            int i;
            for (i = 1; i < 41; i++)
            {
                prefix[i] = prefixsum[r][i] - prefixsum[l-1][i];
                
            }
            int ans=0;
            for (int i = 1; i <= 40; i++)
            {
                if (prefix[i] > 0)
                {
                    int cnt = 0;
                    int j;

                    for (j = i + i; j <= 40; j += i)
                    {
                        cnt += prefix[j];
                    }
                    
                    ans += cnt * prefix[i];
                }
            }
            cout<<ans;
            if(m>0)cout<<" ";
        }
        cout<<endl;
    }
}