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

int main()
{
    ll X, Y;
    cin >> X >> Y;
    ll ans = 0;

    Combination cmb;
    cmb.init(1000005);

    REP(i, X + 1)
    {
        //! x方向に1動かすのをi回行う
        ll x0 = i;
        if ((X - x0) % 2 == 1)
            continue;
        ll x1 = (X - x0) / 2;

        ll y = x0 * 2LL + x1 * 1;
        if (y != Y)
            continue;

        //! (x0+1)^x1;
        ans += cmb.get((x0 + 1) + x1 - 1, x1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}