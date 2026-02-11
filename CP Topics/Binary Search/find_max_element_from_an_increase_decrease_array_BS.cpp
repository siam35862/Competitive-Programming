#include <bits/stdc++.h>
using namespace std;
int find_max_element_inc_dec_sorted_array(int *a, int n)
{
    if(n==1)return 0;
    else
    {
        if(a[0]>a[ 1])return 0;
        if(a[n-1]>a[n-2]) return n-1;
        
    }
    int l = 0, r = n - 1;
    int mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        
       
       if(a[mid]>=a[mid-1]&&a[mid]>a[mid+1])return mid;
       else if(a[mid]>a[mid-1]&&a[mid]>=a[mid+1])return mid;
       else if(a[mid]>a[mid-1])l=mid;
       else r=mid;
       
        

        
    }
    return -1;
}

// 3 5 15 19 13 10 9 6 2
int main()/************************* */
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cout << "Enter array size: ";
    int n;
    cin >> n;
    cout << "Enter increase-desrease sorted array: \n";
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    // int v;
    // cout << "Enter the finding element: ";
    // cin >> v;
    int min_in = find_max_element_inc_dec_sorted_array(a, n);
    if(min_in==-1)cout<<"Invalid Input.\n";
    else cout << "Peak elment is: " << a[min_in]<< endl;
}