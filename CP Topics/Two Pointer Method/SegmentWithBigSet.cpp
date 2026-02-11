#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    int distinct = 0;
    int ans = INT64_MAX, l = 0;
    unordered_map<int, int> cntr;
    for (int r = 0; r < n; r++)
    {
        cntr[a[r]]++;
        if (cntr[a[r]] == 1)
            distinct++;
        while (distinct-((cntr[a[l]]-1==0)?1:0) >= k)
        {
            cntr[a[l]]--;
            if (cntr[a[l]] == 0)
                distinct--;
            l++;
        }
        
        if(distinct>=k)ans = min(ans, r - l + 1);
    }
    if(ans==INT64_MAX)cout<<-1<<endl;
    else
    cout << ans << endl;
}