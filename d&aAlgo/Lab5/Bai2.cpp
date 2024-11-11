#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void solve()
{
    cin >> n >> m;
    vector<int> coins(n);

    for (auto &c : coins) cin >> c;
    int f[m + 1];

    for (int i = 1; i <= m; i++)
        f[i] = INF;

    // f[1] = 0;
    for (int i = 1; i <= m; i++) {
        for (auto c : coins) {
            if (c > i) {
                f[i] = 0;
                continue;
            }
            f[i] = min(f[i], f[i - c] + 1);
        }
    }

    cout << f[m];
    
}

int main()
{
    solve();
}

/*  
5 10
1 2 3 10 5
*/