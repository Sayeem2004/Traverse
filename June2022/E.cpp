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

db r;
db tx, ty;

db sq(db x) {return x*x;}
struct vec {
    db x, y;
    vec() {x=y=0;}
    vec(db X, db Y) {x=X, y=Y;}
    vec operator+(vec b) {return vec(x+b.x, y+b.y);}
    vec operator-(vec b) {return vec(x-b.x, y-b.y);}
    db operator/(vec b) {if (b.x != 0) return x / b.x; else return y / b.y;}
    vec operator*(vec b) {return vec(x*b.x, y*b.y);}
    vec operator*(db k) {return vec(x*k, y*k);}
    vec operator-() {return vec(-x, -y);}
    db distsq() {return x*x + y*y;}
    db dist() {return sqrt(distsq());}
    db distsq(vec b) {return (*this - b).distsq();}
    db dist(vec b) {return sqrt(distsq(b));}
    vec normalize() {return *this * (1.0 / dist());}
    db dot(vec b) {return x*b.x + y*b.y;}
    vec project(vec b) {return b * (dot(b)/b.dot(b));}
    pair<vec, vec> components(vec b) {pair<vec, vec> ans; ans.first = project(b); ans.second = *this - ans.first; return ans;}
    vec reflect(vec b) {b = b.normalize(); return *this - b * (2*dot(b));}
    friend istream &operator>>(istream &input, vec &a) { cin >> a.x >> a.y; return input; }
    friend ostream &operator<<(ostream &output, const vec& a) { return (output << a.x << ' ' << a.y); }
};
vec pos, vel, tmp;
db PI = 3.1415926535897932384626;
vec convert(vec b) {
    return vec(cos(b.x * PI / 180), sin(b.x * PI / 180)) * b.y;
}

void solve() {
    cin >> r;
    cin >> pos;
    cin >> tmp; vel = convert(tmp);
    cin >> tmp; pos = pos - tmp;
    cin >> tmp; vel = vel - convert(tmp);
    pair<vec, vec> cmp = pos.components(vel);
    if (cmp.S.distsq() > sq(r) || (vel.x==0 && vel.y==0)) {
        cout << -1 << nl;
        return;
    }
    vec dir = vel.normalize();
    db mag = sqrt(sq(r) - cmp.S.distsq());
    vec v1 = cmp.S + (dir * mag);
    vec v2 = cmp.S - (dir * mag);
    db t1 = (v1 - pos) / vel;
    db t2 = (v2 - pos) / vel;
    if (t1 > t2) swap(t1, t2);
    if (t2 < 0) {
        cout << -1 << nl;
        return;
    }
    t1 = max((db)0, t1);
    t1 *= 1000; t2 *= 1000;
    cout << (int)round(t1) << nl << (int)round(t2) << nl;
    return;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;

    while (t--) {
        solve();
    }
}
