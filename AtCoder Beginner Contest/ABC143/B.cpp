#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll D[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> D[i];
    }

    ll sum = 0;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            sum += D[i] * D[j];
        }
    }
    cout << sum << endl;
    return 0;
}