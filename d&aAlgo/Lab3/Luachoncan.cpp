#include <bits/stdc++.h>

using namespace std;


int a[1000005];
int cnt = 0, n;

void recursive(int i, string s) {
    if (i == n) {
        int tmp = 0, tmp1 = 0;
        vector<int> v, v1;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') { tmp += a[j]; v.push_back(a[j]); }
            else { tmp1 += a[j]; v1.push_back(a[j]); }
        }
        if (tmp == tmp1) { 
            for (int x : v) cout << x << " ";
            cout << " | ";
            for (int x : v1) cout << x << " ";
            cout << endl;
        }
        return;
    }  
    recursive(i + 1, s + to_string(0));
    recursive(i + 1, s + to_string(1));
    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    recursive(0, "");
}