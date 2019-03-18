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
    int a, b;
    cin >> a >> b;
    int t = b;
    if (b < 10)
        t += a * 10;
    else if (t < 100)
        t += a * 100;
    else
        t += a * 1000;
    string ans = "No";
    REP(i, t)
    {
        if (i * i == t)
            ans = "Yes";
    }
    cout << ans << endl ;
    return 0;
}