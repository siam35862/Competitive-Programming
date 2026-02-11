#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>ans(102,vector<int>(102,-1)),siam(102,vector<int>(102,-1));
int minCost(int i,int j,vector<int>&cuts)
{
    if(i>j)return 0;
    if(siam[i][j]!=-1)return siam[i][j];
    int mincost=INT64_MAX;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=cuts[j+1]-cuts[i-1]+minCost(i,ind-1,cuts)+minCost(ind+1,j,cuts);
        if(cost<mincost)
        {
            mincost=cost;
            ans[i][j]=ind;
        }
    }
    
    return siam[i][j]=mincost;
}
void print(int i,int j,int m,vector<int>&cuts)
{
    if(i>j)return;
    int ind=ans[i][j];
    cout<<cuts[ind]<<" ";
    print(i,ind-1,m,cuts);
    print(ind+1,j,m,cuts);
}
signed main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<int>cuts(m+2,0);
	    int i;
	    for(i=1;i<=m;i++)cin>>cuts[i];
	    cuts[m+1]=n;
	   
        for(i=0;i<=m+1;i++)
        {
            int j;
            for(j=0;j<=m+1;j++)
            {
                siam[i][j]=-1;
                ans[i][j]=0;
            }
        }
      minCost(1,m,cuts);
      print(1,m,m,cuts);
       cout<<endl;
	}

}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
