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
    ll A, B;
    cin >> A >> B;
    if (A >= 13)
        cout << B << endl;
    else if (A >= 6)
        cout << B / 2 << endl;
    else
        cout << 0 << endl;
    return 0;
}