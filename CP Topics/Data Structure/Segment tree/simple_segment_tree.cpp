#include <bits/stdc++.h>
using namespace std;
// increase value of index ind by val
// print summation of range i and j in every query
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
    tree[c_root] = tree[left] + tree[right];
}
void update(int c_node, int l, int r, int ind, int val)
{
    if (ind < l || ind > r)
        return;
    else if (l == r && l == ind)
    {
        tree[c_node] += val;
        return;
    }
    int left = 2 * c_node, right = c_node * 2 + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ind, val);
    update(right, mid + 1, r, ind, val);
    tree[c_node] = tree[left] + tree[right];
}
int summation_range(int c_node, int l, int r, int i, int j)
{
    if (l >= i && r <= j)
        return tree[c_node];
    else if (r < i || l > j)
        return 0;
    int left = 2 * c_node, right = c_node * 2 + 1;
    int mid = (l + r) / 2;
    int val1 = summation_range(left, l, mid, i, j);
    int val2 = summation_range(right, mid + 1, r, i, j);
    return val1 + val2;
}
int main()
{
    int n, q;
    cin >> n >> q;
    a.resize(n + 1);
    tree.resize(3 * n);
    int i;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    // cout << "ok\n";
    initialize(1, 1, n);
    while (q--)
    {
        int l, r, val, ind;
        cin >> ind >> val;
        cin >> l >> r;
        update(1, 1, n, ind, val);

        int ans=summation_range(1, 1, n, l, r);
        cout << ans << endl;
    }
}