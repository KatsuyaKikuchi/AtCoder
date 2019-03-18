#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll G[100005];

ll RN[100005];
ll CN[100005];
ll T[100005];

int main()
{
    ll R, C, K, N;
    cin >> R >> C >> K >> N;
    REP(i, N)
    {
        cin >> G[i].first >> G[i].second;
        G[i].first--;
        G[i].second--;
        RN[G[i].first]++;
        CN[G[i].second]++;
    }

    REP(i, R)
    {
        T[RN[i]]++;
    }

    ll ans = 0;
    REP(i, C)
    {
        ll k = CN[i];
        if (k > K)
            continue;
        ans += T[K - k];
    }

    REP(i, N)
    {
        if (RN[G[i].first] + CN[G[i].second] == K)
            ans--;
        if (RN[G[i].first] + CN[G[i].second] == K + 1)
            ans++;
    }

    cout << ans << endl;
    return 0;
}