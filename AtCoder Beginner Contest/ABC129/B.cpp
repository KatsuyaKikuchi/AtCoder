#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll W[100005];

int main()
{
    ll N;
    cin >> N;
    ll S = 0;
    REP(i, N)
    {
        cin >> W[i];
        S += W[i];
    }

    ll min = INF;
    REP(i, N + 1)
    {
        ll s = 0;
        REP(j, i)
        {
            s += W[j];
        }
        min = std::min(min, abs(S - s - (s)));
    }
    cout << min << endl;
    return 0;
}