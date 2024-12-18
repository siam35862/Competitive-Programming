class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<long long>>siam(n+1,vector<long long>(amount+1,0));
        for(int i=0;i<=n;i++)siam[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)siam[i][j]=min(INT_MAX*1LL,siam[i-1][j]+siam[i][j-coins[i-1]]);
                else siam[i][j]=siam[i-1][j];
            }
        }
        return min(INT_MAX*1LL,siam[n][amount]);
        
    }
};


/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
