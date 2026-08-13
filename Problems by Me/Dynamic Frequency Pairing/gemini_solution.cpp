#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100005;
const int MAXVAL = 200005; // Upper bound for unique values (N + Q)
const int H = 450;          // Heavy threshold (approx sqrt(N) * 1.4)
int BLOCK_SIZE = 2150;      // Optimal block size approx N^(2/3)

struct Query {
    int l, r, t, p, q, id;
};

struct Update {
    int pos, old_val, new_val;
};

struct Item {
    int val_id = 0;
    int score = 0;
};

int n, q_num;
int a[MAXN], cur_a[MAXN];
int orig_val[MAXVAL];
int freq[MAXVAL];
int ans[MAXN];

// Custom comparator for Priority Queue to store values by their original magnitude
struct CompareVal {
    bool operator()(int u, int v) const {
        return orig_val[u] < orig_val[v];
    }
};

// Lazy Max-Heaps for light frequencies [1 ... H-1]
priority_queue<int, vector<int>, CompareVal> max_heap[H];

// List of elements with frequency >= H
vector<int> heavy_list;
int pos_in_heavy[MAXVAL];

vector<Query> queries;
vector<Update> updates;
vector<int> all_vals;

// Mo's 3D Block Comparator
bool cmp_queries(const Query& u, const Query& v) {
    int b_l_u = u.l / BLOCK_SIZE, b_l_v = v.l / BLOCK_SIZE;
    if (b_l_u != b_l_v) return b_l_u < b_l_v;
    int b_r_u = u.r / BLOCK_SIZE, b_r_v = v.r / BLOCK_SIZE;
    if (b_r_u != b_r_v) return b_r_u < b_r_v;
    return u.t < v.t;
}

// Maintains heavy_list in O(1) time
inline void update_heavy(int v) {
    if (freq[v] >= H) {
        if (pos_in_heavy[v] == -1) {
            pos_in_heavy[v] = heavy_list.size();
            heavy_list.push_back(v);
        }
    } else {
        if (pos_in_heavy[v] != -1) {
            int idx = pos_in_heavy[v];
            int last_v = heavy_list.back();
            heavy_list[idx] = last_v;
            pos_in_heavy[last_v] = idx;
            heavy_list.pop_back();
            pos_in_heavy[v] = -1;
        }
    }
}

// O(1) amortized Mo's Add Step
inline void add(int pos) {
    int v = cur_a[pos];
    freq[v]++;
    int f = freq[v];
    if (f < H) {
        max_heap[f].push(v);
    }
    update_heavy(v);
}

// O(1) amortized Mo's Remove Step
inline void remove(int pos) {
    int v = cur_a[pos];
    freq[v]--;
    int f = freq[v];
    if (f > 0 && f < H) {
        max_heap[f].push(v);
    }
    update_heavy(v);
}

inline void apply_update(int t, int cur_l, int cur_r) {
    int pos = updates[t].pos;
    int new_v = updates[t].new_val;
    if (pos >= cur_l && pos <= cur_r) {
        remove(pos);
        cur_a[pos] = new_v;
        add(pos);
    } else {
        cur_a[pos] = new_v;
    }
}

inline void rollback_update(int t, int cur_l, int cur_r) {
    int pos = updates[t].pos;
    int old_v = updates[t].old_val;
    if (pos >= cur_l && pos <= cur_r) {
        remove(pos);
        cur_a[pos] = old_v;
        add(pos);
    } else {
        cur_a[pos] = old_v;
    }
}

void process_query(const Query& qry) {
    int P = min(qry.p, qry.q);
    int Q = max(qry.p, qry.q);

    vector<Item> cand_P, cand_Q;

    // 1. Process light frequencies satisfying P only
    int max_light_P = min(Q - 1, H - 1);
    for (int f = P; f <= max_light_P; f++) {
        while (!max_heap[f].empty() && freq[max_heap[f].top()] != f) {
            max_heap[f].pop();
        }
        if (!max_heap[f].empty()) {
            int v = max_heap[f].top();
            cand_P.push_back({v, orig_val[v] * f});
        }
    }

    // 2. Process light frequencies satisfying both P and Q
    int start_both = max(Q, 1LL);
    int end_both = min(n, H - 1);
    for (int f = start_both; f <= end_both; f++) {
        while (!max_heap[f].empty() && freq[max_heap[f].top()] != f) {
            max_heap[f].pop();
        }
        if (!max_heap[f].empty()) {
            int v1 = max_heap[f].top();
            max_heap[f].pop();

            while (!max_heap[f].empty() && freq[max_heap[f].top()] != f) {
                max_heap[f].pop();
            }

            cand_P.push_back({v1, orig_val[v1] * f});
            cand_Q.push_back({v1, orig_val[v1] * f});

            if (!max_heap[f].empty()) {
                int v2 = max_heap[f].top();
                cand_P.push_back({v2, orig_val[v2] * f});
                cand_Q.push_back({v2, orig_val[v2] * f});
                max_heap[f].push(v2);
            }
            max_heap[f].push(v1); // Restore top elements
        }
    }

    // 3. Process heavy elements (freq >= H)
    for (int v : heavy_list) {
        int f = freq[v];
        if (f >= P) cand_P.push_back({v, orig_val[v] * f});
        if (f >= Q) cand_Q.push_back({v, orig_val[v] * f});
    }

    // 4. Extract Top 2 Candidates for P and Q
    Item p1, p2;
    for (const auto& item : cand_P) {
        if (item.score > p1.score) {
            p2 = p1;
            p1 = item;
        } else if (item.score > p2.score) {
            p2 = item;
        }
    }

    Item q1, q2;
    for (const auto& item : cand_Q) {
        if (item.score > q1.score) {
            q2 = q1;
            q1 = item;
        } else if (item.score > q2.score) {
            q2 = item;
        }
    }

    // 5. Evaluate best valid combination (u != v)
    int max_score = 0;
    if (p1.val_id != 0 && q1.val_id != 0 && p1.val_id != q1.val_id) {
        max_score = max(max_score, p1.score + q1.score);
    }
    if (p1.val_id != 0 && q2.val_id != 0 && p1.val_id != q2.val_id) {
        max_score = max(max_score, p1.score + q2.score);
    }
    if (p2.val_id != 0 && q1.val_id != 0 && p2.val_id != q1.val_id) {
        max_score = max(max_score, p2.score + q1.score);
    }
    if (p2.val_id != 0 && q2.val_id != 0 && p2.val_id != q2.val_id) {
        max_score = max(max_score, p2.score + q2.score);
    }

    ans[qry.id] = max_score;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(pos_in_heavy, -1, sizeof(pos_in_heavy));

    if (!(cin >> n >> q_num)) return 0;

    BLOCK_SIZE = max(1LL, (int)pow(n, 2.0 / 3.0));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cur_a[i] = a[i];
        all_vals.push_back(a[i]);
    }

    // FIX: 1-indexed temp_a array to match pos indexing
    vector<int> temp_a(n + 1);
    for (int i = 1; i <= n; i++) {
        temp_a[i] = a[i];
    }

    for (int i = 0; i < q_num; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            updates.push_back({pos, temp_a[pos], val});
            temp_a[pos] = val;
            all_vals.push_back(val);
        } else {
            int l, r, p, q_thresh;
            cin >> l >> r >> p >> q_thresh;
            queries.push_back({l, r, (int)updates.size() - 1, p, q_thresh, (int)queries.size()});
        }
    }

    // Coordinate Compression
    sort(all_vals.begin(), all_vals.end());
    all_vals.erase(unique(all_vals.begin(), all_vals.end()), all_vals.end());

    for (int i = 1; i <= n; i++) {
        int id = lower_bound(all_vals.begin(), all_vals.end(), a[i]) - all_vals.begin() + 1;
        a[i] = id;
        cur_a[i] = id;
        orig_val[id] = all_vals[id - 1];
    }
    for (auto& u : updates) {
        u.old_val = lower_bound(all_vals.begin(), all_vals.end(), u.old_val) - all_vals.begin() + 1;
        u.new_val = lower_bound(all_vals.begin(), all_vals.end(), u.new_val) - all_vals.begin() + 1;
    }

    sort(queries.begin(), queries.end(), cmp_queries);

    int cur_l = 1, cur_r = 0, cur_t = -1;

    for (const auto& qry : queries) {
        while (cur_t < qry.t) {
            cur_t++;
            apply_update(cur_t, cur_l, cur_r);
        }
        while (cur_t > qry.t) {
            rollback_update(cur_t, cur_l, cur_r);
            cur_t--;
        }
        while (cur_l > qry.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < qry.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < qry.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > qry.r) {
            remove(cur_r);
            cur_r--;
        }

        process_query(qry);
    }

    for (int i = 0; i < (int)queries.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}