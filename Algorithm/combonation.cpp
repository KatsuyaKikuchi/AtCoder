#include "base.hpp"

struct Combination
{
    void init(ll n)
    {
        inv.resize(n + 1);
        pos.resize(n + 1);
        pos[0] = 1;
        inv[0] = 1;
        FOR(i, n + 1, 1)
        {
            pos[i] = (pos[i - 1] * i) % MOD;
        }
        FOR(i, n + 1, 1)
        {
            inv[i] = modpow(pos[i]);
        }
    }

    ll get(ll n, ll r)
    {
        if (n < r || n < 0)
            return 0;
        return (((pos[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
    }

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

    vector<ll> inv;
    vector<ll> pos;
};