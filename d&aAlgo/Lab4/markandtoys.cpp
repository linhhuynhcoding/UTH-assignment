#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void solve()
{
    int k;
    cin >> n >> k;
    set <int> toys = {};

    for (int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        toys.insert(tmp);
    }

    int res = 0;

    for (auto toy : toys) {
        while (k >= toy) res += 1, k -= toy;
    }
    
    cout << res;
}

int main()
{
    solve();
}

/*
7 50
1 12 5 111 200 1000 10

*/