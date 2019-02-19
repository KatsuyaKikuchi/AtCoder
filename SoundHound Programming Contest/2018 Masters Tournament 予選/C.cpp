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
    double n, m, d;
    cin >> n >> m >> d;
    if (d == 0)
        cout << OF64 << (m - 1) / n << endl;
    else
        cout << OF64 << 2 * (m - 1) * (n - d) / (n * n) << endl;
    return 0;
}