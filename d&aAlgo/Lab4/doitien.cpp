#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void dp()
{
    set <int, greater<int>> cash = {100, 50, 20, 10};
    cin >> n;

    int res = 0;

    for (auto money : cash){
        while (n >= money) res += 1, n -= money;
    }
    cout << res;
}

int main()
{
    dp();
}

/*  

*/