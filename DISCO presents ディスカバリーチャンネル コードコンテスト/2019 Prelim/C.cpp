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
    ll N;
    cin >> N;

    ll ans = 0;
    FOR(i, N + 1, 1)
    {
        //! Pの最大値がiである時
        ll mq = N / i;
        ll p = 1, q = 1;
        ll np = 1;
        REP(j, 10)
        {
            p = (p * i) % MOD;
            q = (q * mq) % MOD;
            np = (np * (i - 1)) % MOD;
        }
        ans = (ans + ((MOD + p - np) * q) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}