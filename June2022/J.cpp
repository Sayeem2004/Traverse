// Solved by Maxwell Zen
#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> iset;

typedef long long ll;
typedef long double db;
typedef string str;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<str> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define arr array
#define nl '\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/maxwellzen/CP/debug.cpp"
#endif

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<int N> using ai = array<int, N>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.assign(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

const ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name != "") {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int n, a, b;
str s;
vb on;
vi c;
vvi adj;
vector<vector<pair<int, ll>>> dp;

pair<int, ll> better(pair<int, ll> a, pair<int, ll> b) {
    if (a.F > b.F) return a;
    if (a.F < b.F) return b;
    if (a.S < b.S) return a;
    return b;
}

void dfs(int i, int p) {
    for (int nb : adj[i]) if (nb != p) dfs(nb, i);
    pair<int, ll> v1, v2;
    for (int nb : adj[i]) if (nb != p) {
        v1.F += dp[0][nb].F;
        v1.S += dp[0][nb].S;
        v2.F += dp[1][nb].F;
        v2.S += dp[1][nb].S;
    }
    if (on[i]) v1.F++;
    else v2.F++;
    if (c[i]==-1) {
        dp[0][i] = v1;
        dp[1][i] = v2;
        return;
    }
    pair<int, ll> f1 = v2, f2 = v1;
    f1.S += c[i]; f2.S += c[i];
    dp[0][i] = better(v1, f1);
    dp[1][i] = better(v2, f2);
    return;
}

void solve() {
    cin >> n >> s;
    read(c, n);
    adj.rsz(n);
    F0R(i, n-1) {
        cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }
    on.rsz(n);
    F0R(i, n) on[i] = (s[i]=='1');
    debug(on);
    dp.rsz(2, vector<pair<int, ll>>(n, mp(0, 1e18)));
    dfs(0, 0);
    F0R(i, n) {
        debug(i, dp[0][i]);
        debug(i, dp[1][i]);
    }
    cout << dp[0][0].F << ' ' << dp[0][0].S << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    while (t--) {
        solve();
    }
}
