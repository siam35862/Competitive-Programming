#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxsize (int)2e5

struct node
{
    int sum;
    bool prop;
    int pval;
};
struct node tree[3 * maxsize];
vector<int>a;
void initialize(int cn, int l, int r)
{
    if (l == r)
    {
        tree[cn].sum = a[l];
        tree[cn].prop = false;
        
    }
    else 
    {
        int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    initialize(left, l, mid);
    initialize(right, mid + 1, r);
    tree[cn].sum = tree[left].sum+tree[right].sum;
    tree[cn].prop = false;
    }
}
void propagate(int cn, int l, int r)
{
    if (tree[cn].prop == false)
        return;
    else if (l == r)
    {
        tree[cn].prop = false;
        tree[cn].sum=tree[cn].pval;
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    tree[cn].sum = (r - l + 1)*tree[cn].pval;
    tree[cn].prop = false;
    tree[left].prop = true;
    tree[right].prop = true;
    tree[left].pval = tree[cn].pval;
    tree[right].pval = tree[cn].pval;
    tree[cn].pval=0;
}
void update(int cn, int l, int r, int i, int j,int val)
{
    propagate(cn, l, r);

    if (r < i || l > j)
        return;

    if (l >= i && r <= j)
    {
        tree[cn].prop = true;
        tree[cn].pval=val;
        propagate(cn, l, r);
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, i, j,val);
    update(right, mid + 1, r, i, j,val);
    tree[cn].sum = tree[left].sum + tree[right].sum;
}

int summation_range(int cn, int l, int r, int i, int j)
{
    propagate(cn, l, r);
    if (r < i || l > j)
        return 0;

    if (l >= i && r <= j)
    {
        return tree[cn].sum;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    int v1 = summation_range(left, l, mid, i, j);
    int v2 = summation_range(right, mid + 1, r, i, j);
    return v1 + v2;
}

signed main()
{

    int n, q;
    cin >> n >> q;
    a.resize(n+1);
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    initialize(1, 1, n);
    //cout<<tree[1].sum<<endl;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            int val;
            cin>> val;

            update(1, 1, n, b, c,val);
        }
        else
        {
            int ans = summation_range(1, 1, n, b, c);
            cout << ans << endl;
        }
    }
}