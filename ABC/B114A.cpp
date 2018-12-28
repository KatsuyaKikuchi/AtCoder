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
    int X;
    cin >> X;
    string ans = "NO";
    if (X == 3 || X == 5 || X == 7)
    {
        ans = "YES";
    }
    cout << ans << endl;
    return 0;
}