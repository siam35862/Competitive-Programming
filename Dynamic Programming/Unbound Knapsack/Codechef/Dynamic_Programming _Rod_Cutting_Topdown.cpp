#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> ans(102, vector<int>(102, -1)), siam(102, vector<int>(102, -1));

void print(int i, int j, vector<int> &cuts)
{
    if (j-i==1)
        return;
    int ind = ans[i][j];
    cout << cuts[ind] << " ";
    print(i, ind, cuts);
    print(ind, j, cuts);
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> cuts(m + 2, 0);
        int i;
        for (i = 1; i <= m; i++)
            cin >> cuts[i];
        cuts[m + 1] = n;

        for (i = 0; i <= m + 1; i++)
        {
            int j;
            for (j = 0; j <= m + 1; j++)
            {
                siam[i][j] = 0;
                ans[i][j] = 0;
            }
        }
        int j;
        for (i = 2; i <= m + 1; i++)
        {
            for (j = 0; j + i <= m + 1; j++)
            {
                int k;
                int mincost = INT64_MAX;
                for (k = j + 1; k < j + i; k++)
                {

                    int cost =cuts[j + i] - cuts[j] +siam[j][k] + siam[k][j + i];
                    if(cost<mincost)
                    {
                        mincost=cost;
                        ans[j][i+j]=k;
                    }
                }
                
               
                siam[j][j + i] = mincost;
            }
        }

        print(0, m+1, cuts);
        cout << endl;
    }
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
