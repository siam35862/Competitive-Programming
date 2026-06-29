#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int can_form(int idx, const string &target, const vector<string> &wordbank, vector<int> &dp, vector<vector<string>> &valid_words) {
    if (idx == target.size()) return 1;
    if (dp[idx] != -1) return dp[idx];

    dp[idx] = 0;
    for (const string &word : wordbank) {
        int len = word.size();
        if (idx + len <= target.size()) {
            bool match = true;
            for (int i = 0; i < len; ++i) {
                if (target[idx + i] != word[i]) {
                    match = false;
                    break;
                }
            }
            if (match && can_form(idx + len, target, wordbank, dp, valid_words)) {
                dp[idx] = 1;
                valid_words[idx].push_back(word);
            }
        }
    }
    return dp[idx];
}

void generate_paths(int idx, const string &target, const vector<vector<string>> &valid_words, 
                    vector<string> &current_path, vector<vector<string>> &ans) {
    if (idx == target.size()) {
        ans.push_back(current_path);
        return;
    }

    for (const string &word : valid_words[idx]) {
        current_path.push_back(word);
        generate_paths(idx + word.size(), target, valid_words, current_path, ans);
        current_path.pop_back();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string target;
    cin >> target;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int T = target.size();
    vector<int> dp(T + 1, -1);
    vector<vector<string>> valid_words(T);
    dp[T] = 1;

    if (can_form(0, target, s, dp, valid_words)) {
        cout << "YES\n";
        vector<vector<string>> ans;
        vector<string> current_path;
        
        generate_paths(0, target, valid_words, current_path, ans);

        cout << ans.size() << endl;
        for (const auto &path : ans) {
            for (const auto &word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}