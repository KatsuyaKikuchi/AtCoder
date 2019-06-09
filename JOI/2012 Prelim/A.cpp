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
    ll P = INF, D = INF;
    REP(i, 3)
    {
        ll p;
        cin >> p;
        P = std::min(P, p);
    }
    REP(i, 2)
    {
        ll d;
        cin >> d;
        D = std::min(D, d);
    }
    cout << P + D - 50 << endl;
    return 0;
}