#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[8];
    int i;
    for (i = 0; i < 8; i++)
        cin >> s[i];
    int emptyrow = 0, emptycolumn = 0;
    for(i=0;i<8;i++)
    {
        int j=0;
        int f=1;
        for(j=0;j<8;j++)
        {
            if(s[i][j]=='#')
            {
                f=0;
                break;
            }
        }
        if(f==1)emptyrow++;
    }
     for(i=0;i<8;i++)
    {
        int j=0;
        int f=1;
        for(j=0;j<8;j++)
        {
            if(s[j][i]=='#')
            {
                f=0;
                break;
            }
        }
        if(f==1)emptycolumn++;
    }
    int ans=emptycolumn*emptyrow;
    cout<<ans<<endl;
}