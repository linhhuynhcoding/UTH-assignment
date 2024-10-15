#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int salary[20];
double ans = INF;
int n, m;

void recursive(vector<int> tasks, bool dagiao[20], int currentTask)
{
    if (currentTask == n) {
        double x = 0;
        for (int i = 1; i <= n; i++) x += salary[tasks[i]];
        x /= n;
        double dolech = 0;

        for (int i = 1; i <= n; i++) {
            dolech += sqrt((salary[tasks[i]] - x) * (salary[tasks[i]] - x) / (n - 1));
        }

        ans = min(ans, dolech);
        return; 
    }

    for (int i = 1; i <= m; i++) {
        if (dagiao[i]) continue;

        dagiao[i] = true;

        vector<int> nexttasks = tasks;
        nexttasks[currentTask] = i;
        recursive(nexttasks, dagiao, currentTask + 1);
    }    
}

int main()
{
    
}