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
    ll S = std::min(N, M / 2);
    M -= 2LL * S;
    S += M / 4LL;
    cout << S << endl;
    return 0;
}