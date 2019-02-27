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
    int n, m;
    cin >> n >> m;
    n %= 12;
    double a = 30 * n + (double)m / 2.0;
    double b = 6.0 * m;
    double c = abs(a - b);
    cout << std::min(360.0 - c, c) << endl;
    return 0;
}