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
        for (ll i = 0; (1 << i) <= MOD - 2; ++i, p = (p * p) % MOD)
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

Combination cmb;

ll solve(ll n, ll k)
{
    ll ans = 0;
    if (n % 2 == 0)
    {
        //! z*(n-2z)=k
        ll z = 0, u = n / 4 + 1;
        while (abs(u - z) > 1)
        {
            ll mid = (z + u) / 2;
            if (mid * (n - 2 * mid) <= k)
                z = mid;
            else
                u = mid;
        }
        if (z * (n - 2 * z) == k)
            ans += cmb.get(n / 2, z);

        ll an = n / 2 - z;
        if (an != z && an * (n - 2 * an) == k)
            ans += cmb.get(n / 2, an);
    }
    else
    {
        n = n - 1;
        {
            ll z = 0, u = n / 4 + 1;
            while (abs(u - z) > 1)
            {
                ll mid = (z + u) / 2;
                if (mid * (n - 2 * mid) + mid <= k)
                    z = mid;
                else
                    u = mid;
            }
            if (z * (n - 2 * z) + z == k)
            {
                //! 中央に1を置く時
                ans += cmb.get(n / 2, z);
            }
            ll an = n / 2 - z;
            if (z != an)
            {
                if (an * (n - 2 * an) + n / 2 - an == k)
                    ans += cmb.get(n / 2, an);
            }
        }
        {
            ll z = 0, u = n / 4 + 1;
            while (abs(u - z) > 1)
            {
                ll mid = (z + u) / 2;
                if (mid * (n - 2 * mid) + n / 2 - mid <= k)
                    z = mid;
                else
                    u = mid;
            }
            if (z * (n - 2 * z) + n / 2 - z == k)
            {
                //! 中央に0を置く時
                ans += cmb.get(n / 2, z);
            }
            ll an = n / 2 - z;
            if (z != an)
            {
                if (an * (n - 2 * an) + an == k)
                    ans += cmb.get(n / 2, an);
            }
        }
    }
    return ans % MOD;
}

int main()
{
    int Q;
    cin >> Q;
    cmb.init(100005);

    vector<ll> ans(Q);
    REP(i, Q)
    {
        ll N, K;
        cin >> N >> K;
        ans[i] = solve(N, K);
    }
    REP(i, Q)
    {
        cout << ans[i] << endl;
    }
    return 0;
}