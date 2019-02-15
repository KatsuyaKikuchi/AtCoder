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
    int x, y;
    cin >> x >> y;
    string ans = "Yes";
    if (x == 2 || y == 2)
    {
        ans = "No";
    }
    else if (y <= 6)
    {
        if ((x + y) % 2 == 1)
            ans = "No";
    }
    else if (x >= 8)
    {
        if ((x + y) % 2 == 1)
            ans = "No";
    }
    else
    {
        if ((x + y) % 2 == 0)
            ans = "No";
    }
    cout << ans << endl;
    return 0;
}