#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string solve(ll y)
{
    if (y % 400 == 0)
        return "YES";
    if (y % 100 == 0)
        return "NO";
    if (y % 4 == 0)
        return "YES";
    return "NO";
}

int main()
{
    ll Y;
    cin >> Y;
    cout << solve(Y) << endl;
    return 0;
}