#include <bits/stdc++.h>
using namespace std;
#define int long long
int knapsack(int n, int w, int *val, int *wt) {
    vector<int> dp(w + 1, 0); // 1D DP array
    
    for (int i = 0; i < n; i++) {
        for (int j = w; j >= wt[i]; j--) {
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    return dp[w];
}
signed main() {
    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << knapsack(n, w, val, wt) << endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
