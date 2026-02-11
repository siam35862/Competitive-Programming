#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int> &v, vector<int> temp, int l, int r)
{
    if (r - l == 1)
        return;
    int m = (l + r) / 2;
    merge_sort(v, temp, l, m);
    merge_sort(v, temp, m, r);
    int i = l, j = m, k = l;
    while (k++ < r)
    {
        // if (i < m && j < r)
        // {
        //     if (v[i] < v[j])
        //     {
        //         temp.push_back(v[i++]);
        //     }
        //     else
        //     {
        //         temp.push_back(v[j++]);
        //     }
        // }
        // else if (i < m)
        // {
        //     {
        //         temp.push_back(v[i++]);
        //     }
        // }
        // else
        // {
        //     temp.push_back(v[j++]);
        // }
        (i<m&&j<r)?(v[i]<v[j])?temp.push_back(v[i++]):temp.push_back(v[j++]):(i<m)?temp.push_back(v[i++]):temp.push_back(v[j++]);
    }
    j = 0;

    for (i = l; i < r; i++)
    {
        v[i] = temp[j++];
    }
}
void merge_sort(vector<int> &v)
{
    int n = v.size();
    vector<int> temp;
    int l = 0, r = n;
    merge_sort(v, temp, l, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int i, a[n];
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        a[i] = v[i];
    }
    merge_sort(v);
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}