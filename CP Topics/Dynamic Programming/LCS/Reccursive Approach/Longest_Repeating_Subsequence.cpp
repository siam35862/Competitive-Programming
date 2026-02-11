// C++ program to find longest
// repeating subsequence using memoization

#include <bits/stdc++.h>
using namespace std;

int findLongestRepeatingSubsequence(int i, int j, string &s, vector<vector<int>> &memo) {

    // base case
    if (i == 0 || j == 0)
        return 0;

    // If value is computed, return it.
    if (memo[i - 1][j - 1] != -1)
        return memo[i - 1][j - 1];

    // If characters match and their
    // indices are different
    if (s[i - 1] == s[j - 1] && i != j)
    {

        return memo[i - 1][j - 1] = 1 + findLongestRepeatingSubsequence(i - 1, j - 1, s, memo);
    }

    // Else make two recursive calls.
    return memo[i - 1][j - 1] = max(findLongestRepeatingSubsequence(i - 1, j, s, memo),
                                    findLongestRepeatingSubsequence(i, j - 1, s, memo));
}

int longestRepeatingSubsequence(string s) {

    int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return findLongestRepeatingSubsequence(n, n, s, memo);
}

int main() {

    string s = "ehudfhuigfyghasdfyfgtefee";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}