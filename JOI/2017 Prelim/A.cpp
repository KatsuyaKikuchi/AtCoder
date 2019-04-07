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
    ll A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    ll c = std::max(0LL, -A);
    ll t = c * C;
    if (A < 0)
        t += D;
    t += (B - std::max(0LL, A)) * E;
    cout << t << endl;
    return 0;
}