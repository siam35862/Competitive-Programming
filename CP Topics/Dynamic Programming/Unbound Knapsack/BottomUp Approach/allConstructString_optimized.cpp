#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

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
    
    vector<bool> possible(T + 1, false);
    vector<vector<string>> valid_words(T);
    
    possible[T] = true;

    for (int i = T - 1; i >= 0; i--) {
        for (const string& w : s) {
            int len = w.size();
            
            if (i + len <= T && possible[i + len]) {
                bool match = true;
                for (int j = 0; j < len; j++) {
                    if (target[i + j] != w[j]) {
                        match = false;
                        break;
                    }
                }
                
                if (match) {
                    possible[i] = true;
                    valid_words[i].push_back(w);
                }
            }
        }
    }

    if (!possible[0]) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<string>> all_combinations;
    vector<string> current_path;

    auto dfs = [&](auto& self, int i) -> void {
        if (i == T) {
            all_combinations.push_back(current_path);
            return;
        }

        for (const string& w : valid_words[i]) {
            current_path.push_back(w);
            self(self, i + w.size());
            current_path.pop_back();
        }
    };

    dfs(dfs, 0);

    cout << "YES\n";
    cout << all_combinations.size() << endl;
    for (const auto& path : all_combinations) {
        for (const string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}