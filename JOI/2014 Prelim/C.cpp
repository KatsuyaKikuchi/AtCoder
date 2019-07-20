#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll G[1005];

int main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    REP(i, N)
    {
        cin >> G[i].first >> G[i].second;
    }
    ll sum = 0;
    REP(i, N - 1)
    {
        ll x = G[i + 1].first - G[i].first;
        ll y = G[i + 1].second - G[i].second;
        if (x * y < 0)
            sum += abs(x) + abs(y);
        else
            sum += std::max(abs(x), abs(y));
    }
    cout << sum << endl;
    return 0;
}