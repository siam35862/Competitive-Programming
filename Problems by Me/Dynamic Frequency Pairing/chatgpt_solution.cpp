#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct FastScanner {
    static const int SZ = 1 << 20;

    int idx = 0, size = 0;
    char buf[SZ];

    inline char getChar() {
        if (idx >= size) {
            size = fread(buf, 1, SZ, stdin);
            idx = 0;
            if (!size) return 0;
        }
        return buf[idx++];
    }

    template<class T>
    bool readInt(T &x) {
        char c;
        do {
            c = getChar();
            if (!c) return false;
        } while (c <= ' ');

        x = 0;

        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = getChar();
        }

        return true;
    }
};

struct Update {
    int pos;
    int oldv;
    int newv;
};

struct Query {
    int l, r, t;
    int p, q;
    int id;
};

struct Cand {
    ll score;
    int id;

    bool operator<(const Cand &other) const {
        if (score != other.score)
            return score < other.score;

        return id < other.id;
    }
};

struct Node {
    Cand a{-1, -1};
    Cand b{-1, -1};
};

class SegmentTree {
    int n;
    vector<Node> tr;

    static Node mergeNode(const Node &x, const Node &y) {
        Cand c[4] = {
            x.a, x.b,
            y.a, y.b
        };

        sort(c, c + 4, [](const Cand &A, const Cand &B) {
            return A.score > B.score;
        });

        Node res;

        for (int i = 0; i < 4; ++i) {
            if (c[i].id == -1)
                continue;

            if (res.a.id == -1) {
                res.a = c[i];
            }
            else if (c[i].id != res.a.id) {
                res.b = c[i];
                break;
            }
        }

        return res;
    }

    void update(int p, Node val, int x, int l, int r) {
        if (l == r) {
            tr[x] = val;
            return;
        }

        int m = (l + r) >> 1;

        if (p <= m)
            update(p, val, x << 1, l, m);
        else
            update(p, val, x << 1 | 1, m + 1, r);

        tr[x] = mergeNode(tr[x << 1], tr[x << 1 | 1]);
    }

    Node query(int ql, int qr, int x, int l, int r) const {
        if (ql <= l && r <= qr)
            return tr[x];

        int m = (l + r) >> 1;

        if (qr <= m)
            return query(ql, qr, x << 1, l, m);

        if (ql > m)
            return query(ql, qr, x << 1 | 1, m + 1, r);

        return mergeNode(
            query(ql, qr, x << 1, l, m),
            query(ql, qr, x << 1 | 1, m + 1, r)
        );
    }

public:
    SegmentTree(int n) : n(n) {
        tr.resize(4 * n + 5);
    }

    void update(int p, Node val) {
        update(p, val, 1, 1, n);
    }

    Node query(int l, int r) const {
        if (l > r)
            return Node();

        return query(l, r, 1, 1, n);
    }
};

struct HeapEntry {
    int value;
    int version;

    bool operator<(const HeapEntry &other) const {
        return value < other.value;
    }
};

int main() {

    FastScanner fs;

    int N, Q;
    fs.readInt(N);
    fs.readInt(Q);

    vector<int> initial(N);
    vector<int> all;
    all.reserve(N + Q);

    for (int i = 0; i < N; ++i) {
        fs.readInt(initial[i]);
        all.push_back(initial[i]);
    }

    struct RawQuery {
        int type;
        int a, b, c, d;
    };

    vector<RawQuery> raw;
    raw.reserve(Q);

    for (int i = 0; i < Q; ++i) {

        int type;
        fs.readInt(type);

        if (type == 1) {

            int pos, x;
            fs.readInt(pos);
            fs.readInt(x);

            --pos;

            raw.push_back({1, pos, x, 0, 0});
            all.push_back(x);

        } else {

            int l, r, p, q;

            fs.readInt(l);
            fs.readInt(r);
            fs.readInt(p);
            fs.readInt(q);

            --l;
            --r;

            raw.push_back({2, l, r, p, q});
        }
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int M = all.size();

    auto compress = [&](int x) {
        return lower_bound(all.begin(), all.end(), x) - all.begin();
    };

    vector<int> a(N);

    for (int i = 0; i < N; ++i)
        a[i] = compress(initial[i]);

    /*
        Build updates.
    */

    vector<int> tmp = a;

    vector<Update> updates;
    vector<Query> queries;

    int queryCount = 0;

    for (auto &rq : raw) {

        if (rq.type == 1) {

            int pos = rq.a;
            int nv = compress(rq.b);
            int ov = tmp[pos];

            updates.push_back({pos, ov, nv});

            tmp[pos] = nv;

        } else {

            queries.push_back({
                rq.a,
                rq.b,
                (int)updates.size(),
                rq.c,
                rq.d,
                queryCount++
            });
        }
    }

    /*
        ============================================================
                         3D MO ORDER
        ============================================================
    */

    /*
        Block size can be tuned.

        For N=1e5, around 700-1000 is often faster
        than blindly using N^(2/3), depending on distribution.
    */

    const int BLOCK =
        max(1, (int)pow((double)N, 2.0 / 3.0));

    sort(queries.begin(), queries.end(),
        [&](const Query &A, const Query &B) {

            int al = A.l / BLOCK;
            int bl = B.l / BLOCK;

            if (al != bl)
                return al < bl;

            int ar = A.r / BLOCK;
            int br = B.r / BLOCK;

            if (ar != br) {
                if (al & 1)
                    return ar > br;

                return ar < br;
            }

            if (ar & 1)
                return A.t > B.t;

            return A.t < B.t;
        });

    /*
        ============================================================
                         CURRENT STATE
        ============================================================
    */

    vector<int> cur = a;

    vector<int> freq(M, 0);

    /*
        Version of each value.

        Whenever its frequency changes, version++.
    */
    vector<int> version(M, 0);

    /*
        heap[f] contains candidates that have been inserted
        into frequency f.

        Stale entries are removed lazily.
    */
    vector<priority_queue<HeapEntry>> heap(N + 1);

    SegmentTree seg(N);

    /*
        Get current best two values for exact frequency f.
    */
    auto rebuild = [&](int f) {

        if (f <= 0 || f > N)
            return;

        auto &pq = heap[f];

        /*
            Remove stale entries.

            A candidate is valid iff:
                freq[value] == f
                version[value] == stored version
        */
        while (!pq.empty()) {

            auto e = pq.top();

            if (freq[e.value] == f &&
                version[e.value] == e.version)
                break;

            pq.pop();
        }

        Node node;

        if (!pq.empty()) {

            auto first = pq.top();

            node.a = {
                1LL * all[first.value] * f,
                first.value
            };

            pq.pop();

            /*
                Need second distinct valid candidate.

                Since a value can have multiple stale entries,
                temporarily remove invalid entries.
            */

            while (!pq.empty()) {

                auto e = pq.top();

                if (freq[e.value] == f &&
                    version[e.value] == e.version)
                    break;

                pq.pop();
            }

            if (!pq.empty()) {

                auto second = pq.top();

                if (second.value != first.value) {

                    node.b = {
                        1LL * all[second.value] * f,
                        second.value
                    };
                }
            }

            /*
                Put first candidate back.

                The second remains in the heap.
            */
            pq.push(first);
        }

        seg.update(f, node);
    };

    /*
        Change frequency.
    */

    auto changeValue = [&](int v, int delta) {

        int oldf = freq[v];
        int newf = oldf + delta;

        ++version[v];

        /*
            Old frequency bucket may have changed.
        */
        if (oldf > 0)
            rebuild(oldf);

        freq[v] = newf;

        /*
            Insert into new frequency bucket.
        */
        if (newf > 0) {
            heap[newf].push({
                v,
                version[v]
            });

            rebuild(newf);
        }
    };

    /*
        ============================================================
                         APPLY UPDATE
        ============================================================
    */

    int curL = 0;
    int curR = -1;
    int curT = 0;

    auto applyUpdate = [&](int id, bool forward) {

        const auto &u = updates[id];

        int from = forward ? u.oldv : u.newv;
        int to   = forward ? u.newv : u.oldv;

        int pos = u.pos;

        if (curL <= pos && pos <= curR) {

            changeValue(from, -1);
            changeValue(to, +1);
        }

        cur[pos] = to;
    };

    /*
        ============================================================
                         ANSWERS
        ============================================================
    */

    vector<ll> answer(queryCount);

    for (const Query &qu : queries) {

        while (curT < qu.t) {
            applyUpdate(curT, true);
            ++curT;
        }

        while (curT > qu.t) {
            --curT;
            applyUpdate(curT, false);
        }

        while (curL > qu.l) {
            --curL;
            changeValue(cur[curL], +1);
        }

        while (curR < qu.r) {
            ++curR;
            changeValue(cur[curR], +1);
        }

        while (curL < qu.l) {
            changeValue(cur[curL], -1);
            ++curL;
        }

        while (curR > qu.r) {
            changeValue(cur[curR], -1);
            --curR;
        }

        /*
            Query threshold P.
        */

        Node X = seg.query(qu.p, N);

        /*
            Query threshold Q.
        */

        Node Y = seg.query(qu.q, N);

        /*
            Only these four candidates can possibly matter.
        */

        int c[4] = {
            X.a.id,
            X.b.id,
            Y.a.id,
            Y.b.id
        };

        ll best = 0;

        for (int i = 0; i < 4; ++i) {

            if (c[i] < 0)
                continue;

            for (int j = 0; j < 4; ++j) {

                if (c[j] < 0 || c[i] == c[j])
                    continue;

                int fi = freq[c[i]];
                int fj = freq[c[j]];

                if (fi >= qu.p &&
                    fj >= qu.q) {

                    best = max(
                        best,
                        1LL * all[c[i]] * fi +
                        1LL * all[c[j]] * fj
                    );
                }
            }
        }

        answer[qu.id] = best;
    }

    string out;
    out.reserve(answer.size() * 16);

    for (ll x : answer) {
        out += to_string(x);
        out.push_back('\n');
    }

    fwrite(out.data(), 1, out.size(), stdout);

    return 0;
}