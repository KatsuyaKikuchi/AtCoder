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
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ans = 0;
    REP(i, 3001)
    {
        REP(j, 3001)
        {
            ll g = N - (R * i + j * B);
            if (g >= 0 && g % G == 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}