#include <bits/stdc++.h>
using namespace std;
int find_element_in_r_sorted_array(int *a, int n, int v)
{
    int l = 0, r = n - 1;
    int mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        

        if (a[mid] == v)
            return mid;
        else if (a[l] <= a[mid])
        {
             if ((a[l] <= v) && (v < a[mid]))
                r = mid-1;
            else
            {
                l = mid+1;
            }
        }
        else 
        {
            if ((a[mid] < v) && (v <= a[r]))
                l = mid+1;
            else
            {
                r = mid-1;
            }
        }
       
        

        
    }
    return -1;
}

// 15 19 2 6 9 10 13
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cout << "Enter array size: ";
    int n;
    cin >> n;
    cout << "Enter rotated sorted array: \n";
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    int v;
    cout << "Enter the finding element: ";
    cin >> v;
    int min_in = find_element_in_r_sorted_array(a, n, v);
    if(min_in==-1)cout<<"Not found.\n";
    else cout << "Index of the elment: " << min_in+1 << endl;
}