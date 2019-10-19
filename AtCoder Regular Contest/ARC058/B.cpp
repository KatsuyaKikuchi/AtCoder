#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class Combination
{
public:
    Combination(ll N)
    {
        f.resize(N + 10);
        invf.resize(N + 10);
        f[0] = 1;
        invf[0] = 1;
        REP(i, N)
        {
            f[i + 1] = (f[i] * (i + 1)) % MOD;
            invf[i + 1] = f[i + 1];
        }
        REP(i, N)
        {
            invf[i + 1] = modpow(invf[i + 1], MOD - 2);
        }
    }

    ll get(ll n, ll r)
    {
        if (n < r)
            return 0;
        if (n == r)
            return 1;
        if (r == 0)
            return 1;
        return ((f[n] * invf[r]) % MOD) * invf[n - r] % MOD;
    }

    ll modpow(ll n, ll p)
    {
        ll m = 1;
        REP(i, 35)
        {
            if (((p >> i) & 1) == 1)
            {
                m = (m * n) % MOD;
            }
            n = (n * n) % MOD;
        }
        return m;
    }

private:
    vector<ll> f;
    vector<ll> invf;
};

int main()
{
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    Combination cmb(H + W);
    ll h = H - A, w = W - B;
    ll ans = 0;
    while (h > 0 && w > 0)
    {
        ll bh = h - 1, bw = W - w;
        ll ah = H - h, aw = w - 1;
        ans += (cmb.get(bh + bw, bh) * cmb.get(ah + aw, ah)) % MOD;
        ans %= MOD;
        h--;
        w--;
    }

    cout << ans << endl;
    return 0;
}