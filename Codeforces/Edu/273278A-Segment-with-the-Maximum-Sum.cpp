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
    int ans, pref, suff, sum;
};

node segmentTree[4 * maxsize];
int a[maxsize];

void merge(int c, int l, int r)
{
    int left = 2 * c;
    int right = left + 1;
    segmentTree[c].ans=max(segmentTree[left].ans,segmentTree[right].ans);
    segmentTree[c].sum = segmentTree[left].sum + segmentTree[right].sum;
    segmentTree[c].pref = max(segmentTree[left].pref, segmentTree[left].sum + segmentTree[right].pref);
    segmentTree[c].suff = max(segmentTree[right].suff, segmentTree[left].suff + segmentTree[right].sum);
    segmentTree[c].ans=max(segmentTree[c].ans,segmentTree[left].suff+segmentTree[right].pref);
}

void initialize(int c, int l, int r)
{
    if (l == r)
    {

        segmentTree[c].sum = a[l];
        segmentTree[c].pref = a[l];
        segmentTree[c].suff = a[l];
        segmentTree[c].ans=a[l];
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
        segmentTree[c].sum = val;
        segmentTree[c].pref = val;
        segmentTree[c].suff = val;
        segmentTree[c].ans=val;

        return;
    }
    int left = 2 * c;
    int right = left + 1;

    int mid = (l + r) / 2;
    update(left, l, mid, ind, val);
    update(right, mid + 1, r, ind, val);
    merge(c, l, r);
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
    cout<<max(0LL,segmentTree[1].ans)<<endl;

    while (q--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v1++;

        update(1, 1, n, v1, v2);
        cout<<max(0LL,segmentTree[1].ans)<<endl;

    }
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/