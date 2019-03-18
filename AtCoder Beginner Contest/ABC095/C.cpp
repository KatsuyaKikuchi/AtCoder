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
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll min = INF;
    REP(i, 2 * max(X, Y) + 1)
    {
        //! ABピザをi枚買う
        ll a = i / 2, b = i / 2;
        ll m = C * i + std::max((ll)0, X - a) * A + std::max((ll)0, Y - b) * B;
        min = std::min(min, m);
    }
    cout << min << endl;
    return 0;
}