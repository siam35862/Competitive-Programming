#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    cin>>a>>b>>c;
    if(c%__gcd(a,b))cout<<"No\n";
    else cout<<"Yes\n";

    
    return 0;
}