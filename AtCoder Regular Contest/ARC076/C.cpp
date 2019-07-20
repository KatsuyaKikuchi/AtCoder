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
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    {
        //! 偶数番目に犬
        ll a = 1;
        ll n = N, m = M;
        REP(i, N + M)
        {
            if (i % 2 == 0)
                a *= n--;
            else
                a *= m--;
            a %= MOD;
        }
        ans += a;
    }
    {
        //! 偶数番目に猿
        ll a = 1;
        ll n = N, m = M;
        REP(i, N + M)
        {
            if (i % 2 == 0)
                a *= m--;
            else
                a *= n--;
            a %= MOD;
        }
        ans += a;
    }
    cout << ans % MOD << endl;
    return 0;
}