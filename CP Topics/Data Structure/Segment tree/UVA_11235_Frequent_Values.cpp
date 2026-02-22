#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxsize (int)2e5
int ans=0;
struct node
{
    int leftMost, frLeftMost, rightMost, frRightMost, ans;
    node()
    {
        leftMost = 0;
        frLeftMost = 0;
        rightMost = 0;
        frRightMost = 0;
        ans = 0;
    }
};
struct node tree[3 * maxsize], temp[3 * maxsize];
vector<int> a;

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    return c;
}
void merge(int cn)
{
    int left = 2 * cn;
    int right = left + 1;
    if (tree[left].leftMost == tree[right].rightMost)
    {
        tree[cn].leftMost = tree[left].leftMost;
        tree[cn].rightMost = tree[right].rightMost;
        int tmp = tree[left].frLeftMost + tree[right].frRightMost;
        tree[cn].frLeftMost = tmp;
        tree[cn].frRightMost = tmp;
        tree[cn].ans = tmp;
    }
    else if (tree[left].leftMost == tree[right].leftMost)
    {
        tree[cn].leftMost = tree[left].leftMost;
        tree[cn].rightMost = tree[right].rightMost;
        tree[cn].frLeftMost = tree[left].frLeftMost + tree[right].frLeftMost;
        tree[cn].frRightMost = tree[right].frRightMost;
        tree[cn].ans = max(tree[cn].frLeftMost, tree[right].ans);
    }
    else if (tree[left].rightMost == tree[right].rightMost)
    {
        tree[cn].leftMost = tree[left].leftMost;
        tree[cn].rightMost = tree[right].rightMost;
        tree[cn].frLeftMost = tree[left].frLeftMost;
        tree[cn].frRightMost = tree[left].frRightMost + tree[right].frRightMost;
        tree[cn].ans = max(tree[cn].frRightMost, tree[left].ans);
    }
    else if (tree[left].rightMost == tree[right].leftMost)
    {
        tree[cn].leftMost = tree[left].leftMost;
        tree[cn].rightMost = tree[right].rightMost;
        tree[cn].frLeftMost = tree[left].frLeftMost;
        tree[cn].frRightMost = tree[right].frRightMost;
        tree[cn].ans = max(tree[left].ans, tree[right].ans, tree[left].frRightMost + tree[right].frLeftMost);
    }
    else
    {
        tree[cn].leftMost = tree[left].leftMost;
        tree[cn].rightMost = tree[right].rightMost;
        tree[cn].frLeftMost = tree[left].frLeftMost;
        tree[cn].frRightMost = tree[right].frRightMost;
        tree[cn].ans = max(tree[left].ans, tree[right].ans);
    }
}
void merge2(int cn)
{
    int left = 2 * cn;
    int right = left + 1;
    if (temp[right].ans == 0)
    {
        temp[cn].leftMost = temp[left].leftMost;
        temp[cn].rightMost = temp[left].rightMost;
        temp[cn].frLeftMost = temp[left].frLeftMost;
        temp[cn].frRightMost = temp[left].frRightMost;
        temp[cn].ans = temp[left].ans;
    }
    else
    {
        if (temp[left].leftMost == temp[right].rightMost)
        {
            temp[cn].leftMost = temp[left].leftMost;
            temp[cn].rightMost = temp[right].rightMost;
            int tmp = temp[left].frLeftMost + temp[right].frRightMost;
            temp[cn].frLeftMost = tmp;
            temp[cn].frRightMost = tmp;
            temp[cn].ans = tmp;
        }
        else if (temp[left].leftMost == temp[right].leftMost)
        {
            temp[cn].leftMost = temp[left].leftMost;
            temp[cn].rightMost = temp[right].rightMost;
            temp[cn].frLeftMost = temp[left].frLeftMost + temp[right].frLeftMost;
            temp[cn].frRightMost = temp[right].frRightMost;
            temp[cn].ans = max(temp[cn].frLeftMost, temp[right].ans);
        }
        else if (temp[left].rightMost == temp[right].rightMost)
        {
            temp[cn].leftMost = temp[left].leftMost;
            temp[cn].rightMost = temp[right].rightMost;
            temp[cn].frLeftMost = temp[left].frLeftMost;
            temp[cn].frRightMost = temp[left].frRightMost + temp[right].frRightMost;
            temp[cn].ans = max(temp[cn].frRightMost, temp[left].ans);
        }
        else if (temp[left].rightMost == temp[right].leftMost)
        {
            temp[cn].leftMost = temp[left].leftMost;
            temp[cn].rightMost = temp[right].rightMost;
            temp[cn].frLeftMost = temp[left].frLeftMost;
            temp[cn].frRightMost = temp[right].frRightMost;
            temp[cn].ans = max(temp[left].ans, temp[right].ans, temp[left].frRightMost + temp[right].frLeftMost);
        }
        else
        {
            temp[cn].leftMost = temp[left].leftMost;
            temp[cn].rightMost = temp[right].rightMost;
            temp[cn].frLeftMost = temp[left].frLeftMost;
            temp[cn].frRightMost = temp[right].frRightMost;
            temp[cn].ans = max(temp[left].ans, temp[right].ans);
        }
    }
    
}
void initialize(int cn, int l, int r)
{
    if (l == r)
    {

        tree[cn].frLeftMost = 1;
        tree[cn].frRightMost = 1;
        tree[cn].leftMost = a[l];
        tree[cn].rightMost = a[l];
        tree[cn].ans = 1;
    }
    else
    {
        int left = 2 * cn;
        int right = left + 1;
        int mid = (l + r) / 2;
        initialize(left, l, mid);
        initialize(right, mid + 1, r);
        merge(cn);
    }
}

void frequency_range(int cn, int l, int r, int i, int j)
{

    if (r < i || l > j)
    {
        temp[cn].leftMost = 0;
        temp[cn].frLeftMost = 0;
        temp[cn].rightMost = 0;
        temp[cn].frRightMost = 0;
        temp[cn].ans = 0;

        return;
    }
    if (l >= i && r <= j)
    {
        temp[cn].frLeftMost = tree[cn].frLeftMost;
        temp[cn].frRightMost = tree[cn].frRightMost;
        temp[cn].leftMost = tree[cn].leftMost;
        temp[cn].rightMost = tree[cn].rightMost;
        temp[cn].ans = tree[cn].ans;
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    frequency_range(left, l, mid, i, j);
    frequency_range(right, mid + 1, r, i, j);
    merge2(cn);
}

signed main()
{
    while (1)
    {
        int n, q;
        cin >> n;
        if (n == 0)
            break;
        cin >> q;
        a.resize(n + 1);
        int i;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        initialize(1, 1, n);
        // cout<<tree[1].sum<<endl;
        while (q--)
        {
            int a, b, c;
            cin >> b >> c;
            frequency_range(1, 1, n, b, c);
            int ans = temp[1].ans;
            
            cout << ans << endl;
        }
    }
}