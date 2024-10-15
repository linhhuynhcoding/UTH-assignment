#include <bits/stdc++.h>

using namespace std;



void recursive (vector<int> footprint, int pre, int n) {
    if (n == 0) {
        int sum = 0;
        for (auto i : footprint) {
            cout << i << " + ";
            sum += i;
        }
        cout << "\b\b= " << sum << "\n";
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (i > pre ) continue;

        vector <int> next = footprint;
        next.push_back(i);

        if (n - i >= 0)
            recursive(next, i, n - i);
    }
    
    return;
}


int main(){
    recursive({}, 5, 5);
    return 0;
}