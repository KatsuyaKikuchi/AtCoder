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
    ll K, T;
    cin >> K >> T;
    ll max = 0;
    REP(i, T)
    {
        ll a;
        cin >> a;
        max = std::max(max, a);
    }
    cout << std::max(0LL, 2 * max - K - 1) << endl;

    return 0;
}