#include <bits/stdc++.h>

using namespace std;

void recursive (vector<int> footprint, int n, int current) {
    if (current == n) {
        for (auto i : footprint) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    if (current + 1 <= n) {
        vector<int> next = footprint;
        next.push_back(1);
        recursive(next, n, current + 1);
    }
    if (current + 2 <= n) {

        vector<int> next = footprint;
        next.push_back(2);
        recursive(next, n, current + 2);
    }
    return;
}


int main(){
    recursive({}, 3, 0);

    return 0;
}