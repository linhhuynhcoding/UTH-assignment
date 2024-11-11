#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void solve()
{
    int w;
    cin >> n >> w;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i ++) {
        auto &[u, v] = a[i];
        cin >> u >> v;
    }

    sort (a.begin(), a.end(), [](const pair <int, int> &a, const pair <int, int> &b){
        return (1.0 * a.second / a.first ) > (1.0 * b.second / b.first );
    });

    int res = 0;

    for (auto [u, v] : a) {
        while (w >= u) res += v, w -= u;
    }
    
    cout << res;
}

int main()
{
    solve();
}

/*
4 27
15 30
10 25
1 4
2 6
1 4

*/