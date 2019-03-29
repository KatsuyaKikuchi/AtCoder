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
    ll N, K;
    cin >> N >> K;
    REP(i, K)
    {
        ll x, y;
        cin >> x >> y;
        x = std::min(x, N - x + 1);
        y = std::min(y, N - y + 1);
        cout << (std::min(x, y) - 1) % 3 + 1 << endl;
    }
    return 0;
}