#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define endl '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define maxsize 200005
#define M 1000000007

template <class T>
struct comparator
{
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <class T>
using ordered_set =
    tree<T, null_type, comparator<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

struct node
{
    int val;
};

node segmentTree[4 * maxsize];
int a[maxsize];

void merge(int c, int l, int r)
{
    int left = 2 * c;
    int right = left + 1;
    segmentTree[c].val = segmentTree[left].val + segmentTree[right].val;
}

void initialize(int c, int l, int r)
{
    if (l == r)
    {
        segmentTree[c].val = a[l];
        return;
    }

    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;
    initialize(left, l, mid);
    initialize(right, mid + 1, r);
    merge(c, l, r);
}
void update(int c, int l, int r, int ind, int val)
{
    if (ind < l)
        return;
    else if (r < ind)
        return;
    else if (l == r)
    {
        segmentTree[c].val = val;

        return;
    }
    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;
    update(left, l, mid, ind, val);
    update(right, mid + 1, r, ind, val);
    merge(c, l, r);
}

int query_sum(int c, int l, int r, int i, int j)
{
    if (l > j || r < i)
        return 0;
    else if (l >= i && r <= j)
        return segmentTree[c].val;

    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;
    return query_sum(left, l, mid, i, j) + query_sum(right, mid + 1, r, i, j);
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    initialize(1, 1, n);

    while (q--)
    {
        int type, v1, v2;
        cin >> type >> v1 >> v2;
        v1++;
        if (type == 1)
        {
            update(1, 1, n, v1, v2);
        }
        else
        {

            int sum = query_sum(1, 1, n, v1, v2);
            cout << sum << endl;
        }
    }
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/