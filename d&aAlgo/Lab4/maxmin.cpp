#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;

void solve()
{
    int k;
    cin >> n >> k;
    set<int> nums = {};

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.insert(num);
    }
    int res = abs(*nums.begin() - *nums.rbegin());
    cout << res;
}

int main()
{
    solve();
}

/*
7 3
10 100 300 200 1000 20 30
*/