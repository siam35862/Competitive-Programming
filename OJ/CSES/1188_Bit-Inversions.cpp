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
    int mx = 0;
    int lv, rv;
    int lc = 0, rc = 0;
};

node segmentTree[4 * maxsize];
string s;

void merge(int c, int l, int r)
{
    int left = 2 * c;
    int right = left + 1;
    segmentTree[c].lv = segmentTree[left].lv;
    segmentTree[c].lc = segmentTree[left].lc;
    segmentTree[c].rv = segmentTree[right].rv;
    segmentTree[c].rc = segmentTree[right].rc;
    segmentTree[c].mx = max(segmentTree[left].mx, segmentTree[right].mx);

    if (segmentTree[left].rv == segmentTree[right].lv)
    {

        segmentTree[c].mx = max(segmentTree[c].mx, segmentTree[left].rc + segmentTree[right].lc);

        int mid = (l + r) / 2;
        if (segmentTree[left].mx == mid - l + 1)
            segmentTree[c].lc = segmentTree[left].rc + segmentTree[right].lc;
        else if (segmentTree[right].mx == r - mid)
            segmentTree[c].rc = segmentTree[left].rc + segmentTree[right].lc;

        if (r - l + 1 == segmentTree[left].mx + segmentTree[right].mx)
        {
            segmentTree[c].lc = segmentTree[c].rc = r - l + 1;
        }
    }
}

void initialize(int c, int l, int r)
{
    if (l == r)
    {
        segmentTree[c].mx = 1;
        segmentTree[c].lc = segmentTree[c].rc = 1;
        segmentTree[c].lv = segmentTree[c].rv = s[l - 1] - '0';

        if (segmentTree[c].rv == segmentTree[c].lv)
            return;
    }

    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;
    initialize(left, l, mid);
    initialize(right, mid + 1, r);
    merge(c, l, r);
}
void update(int c, int l, int r, int ind)
{
    if (ind < l)
        return;
    else if (r < ind)
        return;
    else if (l == r)
    {
        segmentTree[c].lv = segmentTree[c].rv = 1 - segmentTree[c].lv;

        return;
    }
    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;
    update(left, l, mid, ind);
    update(right, mid + 1, r, ind);
    merge(c, l, r);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int n = s.size();
    initialize(1, 1, n);

    int q;
    cin >> q;
    while (q--)
    {
        int ind;
        cin >> ind;
        update(1, 1, n, ind);
        cout << segmentTree[1].mx << " ";
    }
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/