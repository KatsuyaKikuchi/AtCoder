#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[100005], Y[100005];
ll NX[100005], MY[100005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> X[i];
    }
    REP(i, M)
    {
        cin >> Y[i];
    }
    {
        //! X軸の使用回数
        int n = N - 1;
        FOR(i, (n + 1) / 2 + 1, 1)
        {
            ll t = ((n - 2 * (i - 1)) * i + (i - 1) * i) % MOD;
            NX[i - 1] = NX[n - i] = t;
        }
    }
    {
        //! Y軸の使用回数
        int m = M - 1;
        FOR(i, (m + 1) / 2 + 1, 1)
        {
            ll t = ((m - 2 * (i - 1)) * i + (i - 1) * i) % MOD;
            MY[i - 1] = MY[m - i] = t;
        }
    }

    ll LX = 0, LY = 0;
    REP(i, N - 1)
    {
        LX += (X[i + 1] - X[i]) * NX[i];
        LX %= MOD;
    }
    REP(i, M - 1)
    {
        LY += (Y[i + 1] - Y[i]) * MY[i];
        LY %= MOD;
    }
    cout << (LX * LY) % MOD << endl;
    return 0;
}