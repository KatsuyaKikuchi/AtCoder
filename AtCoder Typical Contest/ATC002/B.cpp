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
    ll N, M, P;
    cin >> N >> M >> P;

    ll ans = 1;
    ll x = N;
    REP(i, 50)
    {
        if (((P >> i) & 1) == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
    }
    cout << ans << endl;
    return 0;
}