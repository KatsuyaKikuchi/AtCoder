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
    int s[2] = {0, 0};
    REP(i, 2)
    {
        REP(j, 4)
        {
            int t;
            cin >> t;
            s[i] += t;
        }
    }
    cout << std::max(s[0], s[1]) << endl;
    return 0;
}