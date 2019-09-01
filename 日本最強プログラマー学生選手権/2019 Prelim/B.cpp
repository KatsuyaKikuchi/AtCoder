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
ll B[2005];
ll C[2005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }

    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            if (A[i] > A[j])
                B[i]++;
        }
        REP(j, N)
        {
            if (A[i] > A[j])
                C[i]++;
        }
    }

    ll ans = 0;
    ll mul = K * (K - 1) / 2;
    mul %= MOD;
    REP(i, N)
    {
        ans += (B[i] * K) % MOD + (mul * C[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}