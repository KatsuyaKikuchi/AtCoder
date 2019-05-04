#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[1000005];

int main()
{
    ll N, P;
    cin >> N >> P;

    ll ans = 1;
    vector<ll> prime;
    for (ll i = 2; i <= N; ++i)
    {
        if (U[i])
            continue;
        prime.push_back(i);
        for (ll j = i; j <= N; j += i)
            U[j] = true;
    }

    vector<ll> p;
    REP(i, prime.size())
    {
        if (P % prime[i] == 0)
            p.push_back(prime[i]);
    }
    if (p.size() > 0)
    {
        ll mp = p[0];
        REP(i, prime.size())
        {
            if (prime[i] * mp <= N)
            {
                p.push_back(prime[i]);
                mp = std::min(mp, prime[i]);
            }
        }
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    memset(U, 0, sizeof(U));
    REP(i, p.size())
    {
        ll m = p[i];
        for (int j = m; j <= N; j += m)
            U[j] = true;
    }
    FOR(i, N + 1, 1)
    {
        if (P == i)
            continue;
        if (U[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}