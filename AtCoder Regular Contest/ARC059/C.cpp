#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];

int main()
{
    ll N;
    cin >> N;
    ll min = INF, max = -INF;
    REP(i, N)
    {
        cin >> A[i];
        max = std::max(max, A[i]);
        min = std::min(min, A[i]);
    }

    ll ans = INF;
    for (ll n = min; n <= max; ++n)
    {
        ll m = 0;
        REP(i, N)
        {
            ll t = A[i] - n;
            m += t * t;
        }
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}