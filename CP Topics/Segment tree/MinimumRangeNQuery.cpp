#include <bits/stdc++.h>
using namespace std;

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
int main()
{
    

    int n, q;
    cin >> n;
    a.resize(n + 1);
    tree.resize(3 * n);
    int i;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    // cout << "ok\n";
    initialize(1, 1, n);
    cin >> q;
    while (q--)
    {
        int l, r, val, ind;

        cin >> l >> r;
        l++;
        r++;

        int ans = minimum_range(1, 1, n, l, r);
        cout << ans << endl;
    }
}