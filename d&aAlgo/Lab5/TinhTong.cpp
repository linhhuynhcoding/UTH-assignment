#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
bool check = true;


void solve()
{
    int s;
    cin >> n >> s;
    vector <int> a(n);
    for (auto &i : a) cin >> i;
    bool f[n + 1][s + 1];
    int trace[s + 1];

    for (int i = 0; i <= s; i++)
        f[0][i] = false;
    for (int i = 0; i <= n; i++)
        f[i][0] = true;
    
    for (int i = 1; i <= s; i++){
        for (int j = 1; j <= n; j++){
            if (a[j - 1] > i) {
                f[j][i] = f[j - 1][i];       
                continue;
            }
            if (f[j - 1][i - a[j - 1]]) {
                trace[i] = a[j - 1];
                f[j][i] = true;
            }
            else f[j][i] = f[j - 1][i] ;
        }
    }

    if (f[n][s]) cout << "co\n";
    else cout << "khong\n";

                
}

int main()
{
    solve();
}

/*  
5 10
1 2 3 4 5
*/