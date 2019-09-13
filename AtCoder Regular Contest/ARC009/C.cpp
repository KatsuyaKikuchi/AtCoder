#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1777777777;
const ll INF = (ll)1e15;

struct Combination
{
    void init(ll n)
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

//! 階乗MOD
ll P[1000000];

int main()
{
    ll N, K;
    cin >> N >> K;
    Combination cmb;
    cmb.init(1000000);
    P[0] = 1;
    REP(i, K)
    {
        P[i + 1] = (P[i] * (i + 1)) % MOD;
    }

    ll ans = 0;
    //! 選んだK人に異なるものを配る組み合わせ
    REP(i, K + 1)
    {
        ll p = (P[K - i] * cmb.get(K, i)) % MOD;
        if (i % 2 == 0)
            ans += p;
        else
            ans -= (p - MOD);
        ans %= MOD;
    }
    //! N人からK人選ぶ方法
    REP(i, K)
    {
        ans *= (N - i) % MOD;
        ans %= MOD;
    }
    //! (K!)^(MOD-2)1を計算
    ans *= cmb.modpow(P[K]);

    cout << ans % MOD << endl;
    return 0;
}