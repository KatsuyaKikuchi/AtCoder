#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int H, W;
    cin >> H >> W;
    pll g;
    REP(i, H)
    {
        REP(j, W)
        {
            string s;
            cin >> s;
            if (s == "snuke")
                g = pll(i, j);
        }
    }
    cout << (char)('A' + g.second) << g.first + 1 << endl;
    return 0;
}