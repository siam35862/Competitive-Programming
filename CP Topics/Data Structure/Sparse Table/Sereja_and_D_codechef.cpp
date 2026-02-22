#include <bits/stdc++.h>
using namespace std;
#define int long long
int lg[200005];
void log()
{
     lg[0] = 0;
     lg[1] = 0;
     for (int i = 2; i <= 200000; i++)
          lg[i] = lg[i / 2] + 1;
}
void precomputation(vector<vector<int>> &st,vector<int>&a, int n)
{
     int i;
     for (i = 0; i < n; i++)
     {
          st[0][i] = a[i];
     }
     for (i = 1; i <= lg[n] + 2; i++)
     {
          int j;
          for (j = 0; j + (1 << i) <= n; j++)
          {
               st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
          }
     }
}
int range_max(vector<vector<int>> &st, int l, int r)
{
     int i = lg[r - l + 1];
     return max(st[i][l], st[i][r - (1 << i) + 1]);
}
int32_t main()
{
     log();
     int n;
     cin >> n;
     int  i;
     vector<int>diff(n-1),a(n);
     for (i = 0; i < n; i++)
     {
          cin >> a[i];
          if (i > 0)
               diff[i - 1] = a[i] - a[i - 1];
     }
     int m = lg[n] + 2;
     vector<vector<int>> st(m, vector<int>(n, 0));
     precomputation(st,diff,n-1);
     
     int q;
     cin>>q;
     while(q--)
     {
          int t,d;
          cin>>t>>d;
          auto it=upper_bound(a.begin(),a.end(),t);
          it--;
          int k=it-a.begin();
          k++;
          //cout<<k<<endl;
          if(k==1)cout<<1<<endl;
          else
          {
               int l=1,r=k;
               int ans=r;
               while(l<=r)
               {
                    int mid=(l+r)/2;
                    int mx;
                    if(mid==k)mx=0;
                    else mx=range_max(st,mid-1,k-2);
                    //cout<<mid<<" "<<k<<" "<<mx<<endl;
                    if(mx<=d)
                    {
                         ans=mid;
                         r=mid-1;
                    }
                    else l=mid+1;
               }
               cout<<ans<<endl;
          } 
     }
}