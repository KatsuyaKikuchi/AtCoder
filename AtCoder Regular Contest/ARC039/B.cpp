#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Combination
{
    Combination(ll n)
    {
        mNumTbl.resize(n + 1);
        mInverseNumTbl.resize(n + 1);
        mNumTbl[0] = 1;
        mInverseNumTbl[0] = 1;
        FOR(i, n + 1, 1)
        {
            mNumTbl[i] = (mNumTbl[i - 1] * i) % MOD;
        }
        FOR(i, n + 1, 1)
        {
            mInverseNumTbl[i] = modpow(mNumTbl[i]);
        }
    }

    ll get(ll n, ll r)
    {
        if (n < r || n < 0)
            return 0;
        return (((mNumTbl[n] * mInverseNumTbl[r]) % MOD) * mInverseNumTbl[n - r]) % MOD;
    }

    //! バイナリ方で累乗を計算
    ll modpow(ll n)
    {
        ll s = 1, p = n;
        for (ll i = 0; (1LL << i) <= MOD - 2; ++i, p = (p * p) % MOD)
        {
            if (((MOD - 2) & (1 << i)) == 0)
                continue;
            s *= p;
            s %= MOD;
        }
        return s;
    }

    vector<ll> mInverseNumTbl;
    vector<ll> mNumTbl;
};

ll dp[105][505];

int main()
{
    ll N, K;
    cin >> N >> K;

    Combination cmb(100005);
    if (N <= K)
    {
        cout << cmb.get(N, K % N) << endl;
    }
    else
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        REP(i, N)
        {
            REP(j, K + 1)
            {
                REP(k, j + 1)
                {
                    dp[i + 1][j] += dp[i][k];
                    dp[i + 1][j] %= MOD;
                }
            }
        }
        cout << dp[N][K] << endl;
    }

    return 0;
}