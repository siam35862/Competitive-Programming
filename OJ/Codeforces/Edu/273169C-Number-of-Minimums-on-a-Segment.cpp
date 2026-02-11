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
    int cnt;
};

node segmentTree[4 * maxsize];
int a[maxsize];

void merge(int c, int l, int r)
{
    int left = 2 * c;
    int right = left + 1;
    if (segmentTree[left].val == segmentTree[right].val)
    {
        segmentTree[c].val = segmentTree[left].val;
        segmentTree[c].cnt = segmentTree[left].cnt + segmentTree[right].cnt;
    }
    else if (segmentTree[left].val < segmentTree[right].val)
    {
        segmentTree[c].val = segmentTree[left].val;
        segmentTree[c].cnt = segmentTree[left].cnt;
    }
    else
    {
        segmentTree[c].val = segmentTree[right].val;
        segmentTree[c].cnt = segmentTree[right].cnt;
    }
   
}

void initialize(int c, int l, int r)
{
    if (l == r)
    {
        segmentTree[c].val = a[l];
        segmentTree[c].cnt = 1;
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

pair<int, int> query_min_count(int c, int l, int r, int i, int j)
{
    if (l > j || r < i)
        return {INT_MAX, 0};
    else if (l >= i && r <= j)
    {
        
        return {segmentTree[c].val, segmentTree[c].cnt};
    }

    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;

    auto p1 = query_min_count(left, l, mid, i, j);
    auto p2 = query_min_count(right, mid + 1, r, i, j);

    if (p1.first == p2.first)
    {
        return {p1.first, p1.second + p2.second};
    }
    else if (p1.first < p2.first)
        return {p1.first, p1.second};
    else
        return {p2.first, p2.second};
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

            auto it = query_min_count(1, 1, n, v1, v2);
            cout << it.first << " " << it.second << endl;
        }
    }
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/