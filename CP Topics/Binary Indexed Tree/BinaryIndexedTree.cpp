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

int findIndex(int n, int X) // find a index when 1 to up to index sum is greater than X
{
    int l = 1, r = n;
    int ans = -1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(query(m)>X)
        {
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}

signed main()
{
    int n, q;
    cin >> n >> q;
    // the all elments of imagine array is 0
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0) // update a[i] by a[i]+=val
        {
            int ind, val;
            cin >> ind >> val;
            update(ind, n, val);
        }
        else if (type == 1) // sum of range 1 to ind
        {
            int ind;
            cin >> ind;
            int ans = query(ind);
            cout << ans << endl;
        }
        else // sum of range ind1 to ind2
        {
            int ind1, ind2;
            cin >> ind1 >> ind2;
            int ans = query_range(ind1, ind2);
            cout << ans << endl;
        }
    }
    int x;// find index
    cin>> x;
    int ans=findIndex(n,x);
    if(ans==-1)cout<<"Not found.\n";
    else cout<<"The index is "<<ans<<".\n";
}