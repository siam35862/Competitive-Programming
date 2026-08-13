#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 100000;
    const int Q = 100000;

    ofstream out("in.in");

    if (!out) {
        cerr << "Failed to open in.in\n";
        return 1;
    }

    out << n << ' ' << Q << '\n';

    // ------------------------------------------------------------
    // ARRAY
    // ------------------------------------------------------------
    //
    // Construct many frequency patterns:
    //
    //   value 1       -> 10000 times
    //   value 2       -> 5000 times
    //   value 3       -> 2500 times
    //   value 4       -> 1250 times
    //   ...
    //
    // Then medium-frequency blocks and finally distinct values.
    //
    // This makes different [l,r] ranges have very different
    // frequency distributions.
    // ------------------------------------------------------------

    vector<int> a(n + 1);

    int pos = 1;

    vector<int> frequencies = {
        10000,
        5000,
        2500,
        1250,
        625,
        312,
        156,
        78,
        39,
        20,
        10,
        5,
        4,
        3,
        2
    };

    int value = 1;

    for (int cnt : frequencies) {
        for (int j = 0; j < cnt && pos <= n; ++j) {
            a[pos++] = value;
        }
        ++value;
    }

    // Medium frequency groups.
    for (int v = 100; v < 1100 && pos <= n; ++v) {
        int cnt = 20 + (v % 30);

        for (int j = 0; j < cnt && pos <= n; ++j) {
            a[pos++] = v;
        }
    }

    // Remaining positions: distinct values.
    int distinctValue = 100000000;

    while (pos <= n) {
        a[pos++] = distinctValue++;
    }

    for (int i = 1; i <= n; ++i) {
        out << a[i] << (i == n ? '\n' : ' ');
    }

    // ------------------------------------------------------------
    // QUERIES
    // ------------------------------------------------------------

    int updates = 0;
    int type2 = 0;

    for (int i = 1; i <= Q; ++i) {

        // Every 10th query is an update.
        // 90,000 expensive type-2 queries.
        if (i % 10 == 0) {

            ++updates;

            int updatePos =
                (1LL * updates * 7919) % n + 1;

            int newValue;

            if (updates % 3 == 0) {
                // Make an existing frequent value more frequent.
                newValue = 1 + (updates % 15);
            }
            else {
                // New value.
                newValue = 1000000000 - updates;
            }

            out << "1 "
                << updatePos << ' '
                << newValue << '\n';

            continue;
        }

        ++type2;

        int l, r, p, qq;

        int mode = type2 % 20;

        // --------------------------------------------------------
        // 1. Complete range, minimum thresholds
        // --------------------------------------------------------
        if (mode == 0) {

            l = 1;
            r = n;

            p = 1;
            qq = 2;
        }

        // --------------------------------------------------------
        // 2. Complete range, p and q almost equal
        // --------------------------------------------------------
        else if (mode == 1) {

            l = 1;
            r = n;

            p = 499;
            qq = 500;
        }

        // --------------------------------------------------------
        // 3. Complete range, reversed p/q
        // --------------------------------------------------------
        else if (mode == 2) {

            l = 1;
            r = n;

            p = 1000;
            qq = 2;
        }

        // --------------------------------------------------------
        // 4. Almost complete range
        // --------------------------------------------------------
        else if (mode == 3) {

            l = 2;
            r = n;

            p = 1;
            qq = 2;
        }

        // --------------------------------------------------------
        // 5. Shrinking left boundary
        // --------------------------------------------------------
        else if (mode == 4) {

            l = 1 + (type2 % 1000);
            r = n;

            p = 2;
            qq = 3;
        }

        // --------------------------------------------------------
        // 6. Shrinking right boundary
        // --------------------------------------------------------
        else if (mode == 5) {

            l = 1;
            r = n - (type2 % 1000);

            p = 2;
            qq = 3;
        }

        // --------------------------------------------------------
        // 7. Both boundaries moving
        // --------------------------------------------------------
        else if (mode == 6) {

            l = 1 + (type2 % 500);
            r = n - (type2 % 500);

            p = 3;
            qq = 4;
        }

        // --------------------------------------------------------
        // 8. Huge range, p=1 q=huge
        // --------------------------------------------------------
        else if (mode == 7) {

            l = 1;
            r = n;

            p = 1;
            qq = 50000;
        }

        // --------------------------------------------------------
        // 9. Huge range, impossible threshold
        // --------------------------------------------------------
        else if (mode == 8) {

            l = 1;
            r = n;

            p = 50000;
            qq = 100000;
        }

        // --------------------------------------------------------
        // 10. Threshold around largest frequency
        // --------------------------------------------------------
        else if (mode == 9) {

            l = 1;
            r = n;

            p = 9999;
            qq = 10000;
        }

        // --------------------------------------------------------
        // 11. Threshold just above largest frequency
        // --------------------------------------------------------
        else if (mode == 10) {

            l = 1;
            r = n;

            p = 10000;
            qq = 10001;
        }

        // --------------------------------------------------------
        // 12. Small p/q but large range
        // --------------------------------------------------------
        else if (mode == 11) {

            l = 1;
            r = n;

            p = 2;
            qq = 5;
        }

        // --------------------------------------------------------
        // 13. Medium range
        // --------------------------------------------------------
        else if (mode == 12) {

            l = 1000;
            r = n - 1000;

            p = 2;
            qq = 10;
        }

        // --------------------------------------------------------
        // 14. Large range with p=q-ish
        // --------------------------------------------------------
        else if (mode == 13) {

            l = 500;
            r = n - 500;

            p = 49;
            qq = 50;
        }

        // --------------------------------------------------------
        // 15. Range around the high-frequency blocks
        // --------------------------------------------------------
        else if (mode == 14) {

            l = 1;
            r = 30000;

            p = 2;
            qq = 3;
        }

        // --------------------------------------------------------
        // 16. Range cutting through frequency blocks
        // --------------------------------------------------------
        else if (mode == 15) {

            l = 7500;
            r = 25000;

            p = 2;
            qq = 3;
        }

        // --------------------------------------------------------
        // 17. Large range with high threshold
        // --------------------------------------------------------
        else if (mode == 16) {

            l = 100;
            r = n - 100;

            p = 1000;
            qq = 1001;
        }

        // --------------------------------------------------------
        // 18. p=1, q=n
        // --------------------------------------------------------
        else if (mode == 17) {

            l = 1;
            r = n;

            p = 1;
            qq = n;
        }

        // --------------------------------------------------------
        // 19. Very small boundary movement
        // --------------------------------------------------------
        else if (mode == 18) {

            l = (type2 % 50) + 1;
            r = n - (type2 % 50);

            p = 1;
            qq = 2;
        }

        // --------------------------------------------------------
        // 20. Random-looking but deterministic
        // --------------------------------------------------------
        else {

            l = (1LL * type2 * 12347) % 30000 + 1;

            int len =
                50000 +
                (1LL * type2 * 7919) % 50000;

            r = min(n, l + len - 1);

            p =
                1 +
                (1LL * type2 * 37) % 1000;

            qq =
                p +
                1 +
                (1LL * type2 * 97) % 1000;
        }

        // Make sure l <= r.
        if (l > r)
            swap(l, r);

        // Keep thresholds valid and occasionally reversed.
        p = max(1, min(p, n));
        qq = max(1, min(qq, n));

        out << "2 "
            << l << ' '
            << r << ' '
            << p << ' '
            << qq << '\n';
    }

    out.close();

    cerr << "Generated in.in\n";
    cerr << "N       = " << n << '\n';
    cerr << "Q       = " << Q << '\n';
    cerr << "Type 1  = " << updates << '\n';
    cerr << "Type 2  = " << type2 << '\n';

    return 0;
}