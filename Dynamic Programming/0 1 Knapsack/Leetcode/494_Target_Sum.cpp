class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0,i;
        int zero=0; 
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(nums[i]==0)zero++;
        }
        if(zero==n)return (1LL<<n);
        sort(nums.rbegin(),nums.rend());
        if(target<0)
        sum-=target;
        else sum+=target;
        if(sum<0)return 0;
        if(sum%2==1)return 0;
        sum/=2;
        int ans=0;
        int siam[n+1][sum+1];
        for(i=0;i<=sum;i++)siam[0][i]=0;
        for(i=0;i<=n;i++)siam[i][0]=1;
        for(i=1;i<=n;i++)
        {
            int j;
            for(j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    siam[i][j]=siam[i-1][j]+siam[i-1][j-nums[i-1]];
                }
                else siam[i][j]=siam[i-1][j];
            }
        }
        ans=siam[n][sum];
       
        return ans;
        
    }
};

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
