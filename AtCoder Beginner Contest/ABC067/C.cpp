#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[200005];

int main()
{
    int N;
    cin >> N;
    S[0] = 0;
    REP(i, N)
    {
        ll a;
        cin >> a;
        S[i + 1] = a + S[i];
    }

    ll min = INF;
    FOR(i, N, 1)
    {
        min = std::min(min, abs(S[N] - 2 * S[i]));
    }
    cout << min << endl;
    return 0;
}