// Solved by Mohammad Khan
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> V(n);
    for (int i = 0; i < n; i++) cin >> V[i];
    for (int i = 0; i < n; i+=2) {
        if (V[i] < V[i+1]) swap(V[i], V[i+1]);
    }
    for (int i = n-1; i >= 0; i--) {
        if (i % 2 == 1) cout << V[i] << "-";
        else cout << V[i] << " ";
    }
    cout << "\n";
}
