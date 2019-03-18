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
    ll A, B, C;
    cin >> A >> B >> C;
    ll x = std::min(C, B);
    C -= x;
    B -= x;
    ll y = std::min(C, A);
    C -= y;
    A -= y;
    cout << 2 * x + y + std::min(1LL, C) + std::max(0LL, B) << endl;
    return 0;
}