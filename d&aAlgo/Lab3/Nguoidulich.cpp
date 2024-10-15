#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int d[20][20];
int n;
int ans = INF;

void recursive(vector<int> footprint, bool visited[20], int current, int end)
{
    visited[current] = true;

    if (current == end)
    {
        for (int i = 0; i < 20; i++)
        {
            if (visited[i] == false)
                return;
        }
        int cur_ans = 0;
        for (auto i = 1; i < footprint.size(); i++)
        {
            cur_ans = d[footprint[i - 1]][footprint[i]];
        }
        ans = min(ans, cur_ans);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (d[current][i] == INF || visited[i]) continue;

        vector<int> next = footprint;
        next.push_back(i);


        recursive(next, visited, i, end);
    }
}

int main()
{
}