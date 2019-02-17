#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll N, M;
    cin >> N >> M;

    std::map<ll, ll> map;
    map[0] = 1;
    ll ans = 0;
    ll sum = 0;
    REP(i, N)
    {
        ll a;
        cin >> a;
        a %= M;
        sum = (sum + a) % M;
        ans += map[sum]++;
    }

    cout << ans << endl;
    return 0;
}