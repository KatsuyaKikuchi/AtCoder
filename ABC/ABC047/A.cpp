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
    int n[3];
    REP(i, 3)
    {
        cin >> n[i];
    }
    sort(n, n + 3);
    string ans = "No";
    if (n[0] + n[1] == n[2])
        ans = "Yes";
    cout << ans << endl;
    return 0;
}