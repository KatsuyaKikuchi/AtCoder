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
    ll X, Y;
    cin >> X >> Y;
    string A = "No";
    if (abs(X - Y) % 2 == 0 && std::min(X, Y) > 0)
    {
        ll z = abs(X - Y) / 2;
        ll max = std::max(X, Y);

        if ((max - 3 * z) % 4 == 0 && X + Y - max >= z)
            A = "Yes";
    }
    cout << A << endl;
    return 0;
}