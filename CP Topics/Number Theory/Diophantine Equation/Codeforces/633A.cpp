#include <bits/stdc++.h>
using namespace std;

#define int long long

int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool has_positive_solution(int a, int b, int c) {
    int x0, y0;
    int g = extgcd(a, b, x0, y0);

    if (c % g != 0) return false;

    x0 *= (c / g);
    y0 *= (c / g);

    int step_x = b / g;
    int step_y = a / g;

    int x_min = x0 % step_x;
    if (x_min <= 0) {
        x_min += step_x;
    }

    int k = (x_min - x0) / step_x;
    int y_max = y0 - k * step_y;
    

    return (y_max >= 0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    if (cin >> a >> b >> c) {
        if (has_positive_solution(a, b, c)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}