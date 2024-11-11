#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void solve()
{
    cin >> n;
    vector<pair<int, int>> schedules(n);
    int fix_min = INF;
    int fix_max = -INF;

    for (auto &[s, f] : schedules){
        cin >> s >> f;
        fix_min = min(fix_min, f);
        fix_max = max(fix_max, f);
    } 

    int dp[fix_max + 1];

    for (int i = 0; i <= fix_max; i++) dp[i] = 0;

    for (int i = 1; i <= fix_max; i++) {
        for (auto [s, f] : schedules) {
            // cout << s << " " << f << "\n";
            if (f != i){
                continue;
            }

            dp[i] = max(dp[i], dp[s] + 1);
        }
    }
    cout << dp[fix_max];
        
}

int main()
{
    solve();
}

/*  
5
1 3
3 5
2 4
1 2
4 5
*/