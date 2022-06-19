// Solved by Ivan Wei
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define F0R(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define R0F(i, n) for (int i = n - 1; i >= 0; --i)
#define ROF(i, a, b) for (int i = b - 1; i >= a; --i)

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin;
    if (argc >= 2) {
        fin.open("a.in");
        cin.rdbuf(fin.rdbuf());
    }

    int n;
    cin >> n;

    // Fill DP array
    int sandwiches[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            sandwiches[i][j] = c == '.';
        }
    }

    // Iterate through rings, inwards
    for (int i = n - 2; i >= 0; --i) {
        // Set the corner
        if (sandwiches[i][i] != 0)
            sandwiches[i][i] = min(sandwiches[i][i + 1], sandwiches[i + 1][i]) + 1;
        // Iterate towards top and left
        for (int j = i - 1; j >= 0; --j) {
            // Left
            if (sandwiches[i][j] != 0)
                sandwiches[i][j] = min(sandwiches[i][j + 1], sandwiches[i + 1][j]) + 1;

            // Top
            if (sandwiches[j][i] != 0)
                sandwiches[j][i] = min(sandwiches[j][i + 1], sandwiches[j + 1][i]) + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += sandwiches[i][j];
        }
    }
    cout << sum << "\n";
}
