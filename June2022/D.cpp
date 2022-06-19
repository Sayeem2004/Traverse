// Solved by Mohammad Khan
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define PI 3.141592

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long double d, k; cin >> d >> k;
    d = d * d; k = k / PI;
    vector<long double> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
        R[i] = R[i] * R[i];
    }
    sort(R.begin(), R.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        long double upper = d+k-R[i];
        long double lower = d-k-R[i];
        auto upper_itr = upper_bound(R.begin()+i+1, R.end(), upper);
        auto lower_itr = lower_bound(R.begin()+i+1, R.end(), lower);
        ans += max((int)(upper_itr - lower_itr), 0);
    }
    cout << ans << "\n";
}
