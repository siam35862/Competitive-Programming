#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxSize (int)2e5

int tree[maxSize + 1];
void update(int ind, int n, int val)
{
    while (ind <= n)
    {
        tree[ind] += val;
        ind = ind + (ind & (-ind));
    }
}
int query(int ind)
{
    int sum = 0;
    while (ind > 0)
    {
        sum += tree[ind];
        ind -= ind & (-ind);
    }
    return sum;
}
int query_range(int i, int j)
{
    int sum1 = query(i - 1);
    int sum2 = query(j);
    return sum2 - sum1;
}

int findIndex(int n, int X) // find a index when 1 to up to index sum is greater than or equal to X
{
    int l = 1, r = n;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (query(m) >= X)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

signed main()
{
    int t;
    cin >> t;
    int cs=0;
    while (t--)
    {
        
        cs++;
        cout<<"Case "<<cs<<":\n";
        int n, q;
        cin >> n >> q;
       
        int a[n + 1];
        int i;
        for(i=0;i<=n;i++)tree[i]=0;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            update(i, n, a[i]);
        }
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int ind;
                cin >> ind ;
                ind++;
                int ans=query_range(ind,ind);
                cout<<ans<<endl;
                ans*=-1;
                update(ind,n,ans);
            }
            else if (type == 2) 
            {
                int ind,val;
                cin >> ind>>val;
                ind++;
                update(ind,n,val);
                
            }
            else
            {
                int ind1, ind2;
                cin >> ind1 >> ind2;
                ind1++;ind2++;
                int ans = query_range(ind1, ind2);
                cout << ans << endl;
            }
        }
    }
}