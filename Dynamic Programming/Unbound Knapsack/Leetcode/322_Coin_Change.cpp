class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0)return 0;
        vector<vector<long long>>siam(n+1,vector<long long>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++)siam[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                
                if(coins[i-1]<=j)siam[i][j]=min(siam[i-1][j],1+siam[i][j-coins[i-1]]);
                else siam[i][j]=siam[i-1][j];
                
            }
           
        }
        if(siam[n][amount]==INT_MAX)return -1;
        return siam[n][amount];
        
    }
};

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
