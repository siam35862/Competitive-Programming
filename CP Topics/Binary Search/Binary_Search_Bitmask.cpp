#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int> &a, int query)
{
    int bit, i = 0;
    for (bit = 0; (1 << bit) < a.size(); bit += 1);
    
        
    for (bit -= 1; bit >= 0; bit -= 1)
    {
        
        if (i + (1 << bit) < a.size() && a[i + (1 << bit)] <= query)
        {
            i += (1 << bit);
            
        }
    }
    if (a[i] == query)
        return i;

    return -1;
}
int left_binary_search(vector<int> &a, int query)
{
    int bit, i = 0;
    for (bit = 0; (1 << bit) < a.size(); bit += 1)
        // bit=log2(a.size());
        ;
    // find i = the rightmost position for which a[i] < query
    for (bit -= 1; bit >= 0; bit -= 1)
    {
        if (i + (1 << bit) < a.size() && a[i + (1 << bit)] <= query)
        {
            i += (1 << bit);
        }
    }

    if (query < a[i])
        return -1;
    return i;
}
int right_binary_search(vector<int> &a, int query)
{
    int bit, i = 0;
    for (bit = 0; (1 << bit) < a.size(); bit += 1)
        // bit=log2(a.size());
        ;
    // find i = the rightmost position for which a[i] < query
    for (bit -= 1; bit >= 0; bit -= 1)
    {
        if (i + (1 << bit) < a.size() && a[i + (1 << bit)] < query)
        {
            i += (1 << bit);
        }
    }

    if (i + 1 >= a.size())
        return -1;
    return i + 1;
}
int main()
{
    int n;
    // cin >> n;
    n = 9;
    vector<int> v = {1,3,5,7,9,12,12,16};
    cout << left_binary_search(v, 0) << endl
         << left_binary_search(v, 11) << endl
         << left_binary_search(v, 18) << endl;
    cout << right_binary_search(v, 0) << endl
         << right_binary_search(v, 11) << endl
         << right_binary_search(v, 19) << endl;
    cout << binary_search(v, 1) << endl
         << binary_search(v, 12) << endl
         << binary_search(v, 16) << endl;
}
