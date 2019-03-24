#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N[10];

int main()
{
    REP(i, 5)
    {
        cin >> N[i];
    }

    ll sum = N[4];
    ll a = std::min((5 * 5 * 5 - 4 * 4 * 4) * N[3], N[0]);
    sum += N[3];
    N[0] -= a;
    ll b = std::min(N[2] * 7, N[1]);
    ll c = std::min((5 * 5 * 5 - 3 * 3 * 3) * N[2] - b * (2 * 2 * 2), N[0]);
    sum += N[2];
    N[1] -= b;
    N[0] -= c;
    ll d = (N[1] + 7) / 8;
    ll e = std::min((5 * 5 * 5 * d - 2 * 2 * 2 * N[1]), N[0]);
    sum += d;
    N[0] -= e;
    sum += (N[0] + 124) / 125;

    cout << sum << endl;
    return 0;
}