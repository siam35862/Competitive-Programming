#include <bits/stdc++.h>
using namespace std;

void solve(int n);
int Binary_Search(int a[], int n, int value); 

int main() {
    int n;
    cin >> n;
    solve(n);
}

void solve(int n) {
    int a[n], m;
    cin >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        int result = Binary_Search(a, n, value);
        cout << result << endl;
    }
}

int Binary_Search(int a[], int n, int value) {
    int l = 0, r = n - 1;
    int result = -1;  
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        
        if(a[mid]<value)
        {
            result =mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    
    
    return  result + 2;
}
