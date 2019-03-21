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
        mInverseNumTbl.resize(n + 1);
        mNumTbl.resize(n + 1);
        mNumTbl[0] = 1;
        mInverseNumTbl[0] = 1;
        FOR(i, n + 1, 1)
        {
            mNumTbl[i] = (mNumTbl[i - 1] * i) % MOD;
        }
        FOR(i,n+1,1)
        {
            mInverseNumTbl[i]=modpow(mNumTbl[i]);
        }
    }

    ll get(ll n, ll r)
    {
        return (((mNumTbl[n] * mInverseNumTbl[r]) % MOD) * mInverseNumTbl[n - r]) % MOD;
    }

    ll modpow(ll n)
    {
        ll s = 1, p = n;
        for (ll i = 0; (1 << i) <= MOD - 2; ++i, p = (p * p) % MOD)
        {
            if (((MOD - 2) & (1 << i) )== 0)
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
    ll H, W;
    cin >> H >> W;
    Combination cmb;
    cmb.init(H + W);
    cout << cmb.get(H + W - 2, H - 1) << endl;
    return 0;
}