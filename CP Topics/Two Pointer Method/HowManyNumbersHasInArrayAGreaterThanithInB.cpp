#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m],i,j;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<m;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    int countOfB[m];
    j=0;
    for(i=0;i<m;i++)
    {
        while(j<n&&a[j]<b[i])j++;
        countOfB[i]=j;
        cout<<countOfB[i]<<" "<<b[i]<<endl;
    }
}