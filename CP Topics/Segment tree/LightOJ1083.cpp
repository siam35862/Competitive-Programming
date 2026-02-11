#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a, tree;
void initialize(int c_root, int l, int r)
{
    if (l == r)
    {
        tree[c_root] = a[l];
        return;
    }
    int left = 2 * c_root, right = c_root * 2 + 1;
    int mid = (l + r) / 2;
    initialize(left, l, mid);
    initialize(right, mid + 1, r);
    tree[c_root] = min(tree[left], tree[right]);
}

int minimum_range(int c_node, int l, int r, int i, int j)
{
    if (l >= i && r <= j)
        return tree[c_node];
    else if (r < i || l > j)
        return INT_MAX;
    int left = 2 * c_node, right = c_node * 2 + 1;
    int mid = (l + r) / 2;
    int val1 = minimum_range(left, l, mid, i, j);
    int val2 = minimum_range(right, mid + 1, r, i, j);
    return min(val1, val2);
}
signed main()
{

    int t;
    cin >> t;
    int cs=0;
    while (t--)
    {
        cs++;
        cout<<"Case "<<cs<<": ";
        int n, q;
        cin >> n;
        a.resize(n + 1);
        tree.resize(3 * n);
        int i;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        // cout << "ok\n";
        initialize(1, 1, n);
        int l=1,r=n;
        int ans=0;
        while(l<r)
        {
            int width=r-l+1;
            int height=minimum_range(1,1,n,l,r);
            ans=max(ans,height*width);
            if(a[l]<a[r])l++;
            else r--;

        }
        cout<<ans<<endl;
    }
}