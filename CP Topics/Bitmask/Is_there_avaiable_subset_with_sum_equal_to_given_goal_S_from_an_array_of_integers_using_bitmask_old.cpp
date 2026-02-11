#include<bits/stdc++.h>
using namespace std;
void finding_subset(int *a,int n,long long t_sum)
{
    int mask;
    for(mask=0;mask<(1<<n);mask++)
    {
        long long sum=0;
        int i;
        for(i=0;i<n;i++)
        {
            if((mask&(1<<i)))sum+=a[i];
        }
        if(sum==t_sum)
        {
            cout<<"YES\n";
            return ;
        }
    }
    cout<<"NO\n";
}
int main()
{
    cout<<"Enter an integer(<20): ";
    int n;
    cin >>n;
    int i;
    long long t_sum=0;
    int a[n];
    cout<<"Enter "<<n<<" integers: "; 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout << "Target sum of finding subset: ";
    cin>>t_sum;
    finding_subset(a,n,t_sum);
    
}