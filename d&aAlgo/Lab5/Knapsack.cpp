#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void solve()
{
    int w;
    cin >> n >> w;
    vector<pair <int, int>> dovat(n);
    for (auto &[u, v] : dovat) cin >> u;
    for (auto &[u, v] : dovat) cin >> v;

    int f[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
        f[i][0] = 0;
    for (int i = 0; i <= w; i++)
        f[0][i] = 0;

    for (int i = 1; i <= w; i++){
        for (int j = 1; j <= n; j++) {
            auto [x, v] = dovat[j - 1];
            f[j][i] = f[j - 1][i];
            if (x > i) continue;

            f[j][i] = max(f[j][i], f[j - 1][i - x] + v);
        }
    }
    
    cout << "Phuong an toi uu la : ";
    cout << f[n][w]; 

}

int main()
{
    solve();
}

/*  
5 40
46 40 42 38 10
12 19 19 15 8
*/