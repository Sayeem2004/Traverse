// Solved by Maxwell Zen & Alvin Li
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define pb push_back
#define rsz resize
#define mp make_pair
#define F first
#define S second
#define nl '\n'
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name != "") {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int n, m;
vvb on, vis;
str s;
vvi ans;
queue<pi> q;

void solve() {
    cin >> n >> m;
    on.rsz(n, vb(m));
    vis.rsz(n, vb(m, false));
    F0R(i, n) {
        cin >> s;
        F0R(j, m) on[i][j] = (s[j]=='0');
    }
    ans.rsz(n, vi(m, 1e9));
    F0R(i, n) F0R(j, m) {
        if (on[i][j]) {
            ans[i][j] = 1;
            vis[i][j] = true;
            q.push(mp(i, j));
        }
    }
    if (q.empty()) {
        F0R(i, n) F0R(j, m) {
            ans[i][j] = max(i, n-1-i) + max(j, m-1-j) + 1;
        }
    } else {
        while (! q.empty()) {
        pi cur = q.front();
            int x = cur.F, y = cur.S;
            q.pop();
            F0R(d, 4) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (btw(nx, 0, n-1) && btw(ny, 0, m-1)) {
                    if (!vis[nx][ny] && ans[nx][ny] > ans[x][y]+1) {
                        vis[nx][ny] = true;
                        ans[nx][ny] = ans[x][y]+1;
                        q.push(mp(nx, ny));
                    }
                }
            }
        }
    }
    F0R(i, n) {
        F0R(j, m) cout << ans[i][j] << ' ';
        cout << nl;
    }
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;

    while (t--) {
        solve();
    }
}
