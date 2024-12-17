
class Solution {
public:

    vector<vector<int>> siam;
    int minimumCost(int i,int j,vector<int>&cuts)
    {
        if(i>j)return 0;
        if(siam[i][j]!=-1)return siam[i][j];
        int mincost=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
           mincost=min(mincost,cuts[j+1]-cuts[i-1] + minimumCost(i,ind-1,cuts) + minimumCost(ind+1,j,cuts));
        }
        return siam[i][j]=mincost;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();     
        cuts.insert(cuts.begin() + 0, 0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        siam.resize(m+2,vector<int>(m+2,-1));
        return minimumCost(1,m,cuts);
    }
};

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
