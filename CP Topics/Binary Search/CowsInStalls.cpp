#include <bits/stdc++.h>

using namespace std;
#define int long long
#define d long double
int n,k;

int Binary_Search(int a[],  int value) {
    int l = 0, r = n - 1;
    int result = n;  
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        
        if (a[mid] >= value) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    
    return  result + 1;
}
bool f(int *a,int md)
{
    int c=1;
    int i=0;
    while(i<n)
    {
        int v=a[i]+md;
        int j=Binary_Search(a,v);
        if(j>n)
        {
            return c>=k;
        }
        else 
        {
            i=j;
            c++;
            return c>=k;

        }
    }
    return c>=k;
}
signed main()
{
    cin >>n>>k;
    int a[n];
    int i;
    int ll=0,sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
       
    }
    int l=0,r=1e18,ans;
    ans=l;
    i=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(f(a,mid))
        {
            ans=max(mid,ans);
            l=mid+1;
        }
        else r=mid-1;
        i++;
    }
    
    cout<<ans<<endl;
}