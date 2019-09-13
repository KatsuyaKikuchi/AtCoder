#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll D[1000];

int main()
{
    ll N;
    cin >> N;
    ll s = 0;
    ll max = 0;
    REP(i, N)
    {
        cin >> D[i];
        s += D[i];
        max = std::max(max, D[i]);
    }

    cout << s << endl;
    cout << std::max(0LL, max - (s - max)) << endl;
    return 0;
}