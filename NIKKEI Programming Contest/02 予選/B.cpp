#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll)1e15;

pll D[100005];
ll S[100005];

int main()
{
    ll N;
    cin >> N;
    ll max = 0;
    REP(i, N)
    {
        cin >> D[i].first;
        D[i].second = i;
        S[D[i].first]++;
        max = std::max(max, D[i].first);
    }
    if (D[0].first != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(D, D + N, [](pll a, pll b) { return a.first < b.first; });
    ll ans = 1;
    FOR(i, max + 1, 1)
    {
        if (S[i] == 0)
        {
            ans = 0;
            break;
        }
        if (S[0] != 1)
        {
            ans = 0;
            break;
        }
        ll p = 1;
        REP(j, S[i])
        {
            p = (p * S[i - 1]) % MOD;
        }
        ans = (ans * p) % MOD;
    }
    cout << ans << endl;
    return 0;
}