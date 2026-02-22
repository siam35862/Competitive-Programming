#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i = 1;
    char s[50], *p;

    scanf("%d ", &t);

    while (1) {
        p = gets(s);

        if (p == NULL) {
            return 0;
        }

        if (strcmp(s, "") == 0) {
            // End of a test case
            i++;

            continue;
        }

        printf("test %d: %s\n", i, s);
    }

    return 0;
}
