#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    
    int a[n],b[m],i,j;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];

    j = 0;
    i = 0;

    while (i < n || j < m)
    {
        if (j == m || (i < n && a[i] < b[j]))
        {
            cout << a[i] ;

            i++;
        }
        else
        {

            cout << b[j] ;
            j++;
        }
        if(i < n || j < m)cout<<" ";
    }
    cout << endl;
}