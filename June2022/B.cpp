// Solved by Alvin Li
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

void solve () {
    int n; cin >> n;
    vi v(n);
    for(int& a : v) cin >> a;

    unordered_map<int,int> m;
    for(int a : v) ++m[a];

    for(auto p : m)
        if(p.second >= (n+1)/2 + 1) {
            cout  << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main () {
    int t; cin >> t;
    while (t--) solve();
}
