#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[2005];

int main()
{
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        ll a = 0;
        REP(j, N)
        {
            if (A[i] > A[j])
                a++;
        }
        ll b = 0;
        FOR(j, N, i + 1)
        {
            if (A[i] > A[j])
                b++;
        }
        ans += b * K + ((K * (K - 1) / 2) % MOD) * a;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}