#include <bits/stdc++.h>
using namespace std;
// increase value of range i and j by val
// print summation of range i and j in every query
#define int long long
#define maxsize (int)(2e5+5)
struct node
{
    int sum;
    int prop;
};
int a[maxsize];
struct node tree[4 * maxsize];

void initialize(int c_root, int l, int r)
{
    if (l == r)
    {
        tree[c_root].sum = a[l];
        tree[c_root].prop = 0;
        return;
    }
    int left = 2 * c_root, right = c_root * 2 + 1;
    int mid = (l + r) / 2;
    initialize(left, l, mid);
    initialize(right, mid + 1, r);
    tree[c_root].sum = tree[left].sum + tree[right].sum;
    tree[c_root].prop = 0;
}
void update_range(int c_node, int l, int r, int i, int j, int val)
{
    if (l >= i && r <= j)
    {
        tree[c_node].sum += (r - l + 1) * val;
        tree[c_node].prop += val;
        return ;
    }
    else if (r < i || l > j)
        return;
    int left = 2 * c_node, right = c_node * 2 + 1;
    int mid = (l + r) / 2;
    update_range(left, l, mid, i, j, val);
    update_range(right, mid + 1, r, i, j, val);
    tree[c_node].sum = tree[left].sum + tree[right].sum + (r - l + 1) * tree[c_node].prop;
}
int summation_range(int c_node, int l, int r, int i, int j, int carry)
{
    if (l >= i && r <= j)
        return tree[c_node].sum + (r - l + 1) * carry;
    else if (r < i || l > j)
        return 0;
    int left = 2 * c_node, right = c_node * 2 + 1;
    int mid = (l + r) / 2;
    int val1 = summation_range(left, l, mid, i, j, carry + tree[c_node].prop);
    int val2 = summation_range(right, mid + 1, r, i, j, carry + tree[c_node].prop);
    return val1 + val2;
}
signed main()
{
    int n, q;
    cin >> n >> q;

    int i;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    //  cout << "ok\n";
    initialize(1, 1, n);
    // cout << "ok\n";
    while (q--)
    {
       // 
        int type;
        cin >> type;
        if (type == 2)
        {
            int ind;
            cin >> ind;
            int ans = summation_range(1, 1, n, ind, ind, 0);
            cout << ans << endl;
        }
        else
        {
            int l, r, v;
            cin >> l >> r >> v;
            
            update_range(1, 1, n, l, r, v);
        }
    }
}