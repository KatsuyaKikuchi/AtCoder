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
    ll N, M, L;
    cin >> N >> M >> L;
    ll P, Q, R;
    cin >> P >> Q >> R;

    ll max = 0;
    {
        max = std::max((N / P) * (M / Q) * (L / R), max);
        max = std::max((N / P) * (M / R) * (L / Q), max);
        max = std::max((N / Q) * (M / P) * (L / R), max);
        max = std::max((N / Q) * (M / R) * (L / P), max);
        max = std::max((N / R) * (M / P) * (L / Q), max);
        max = std::max((N / R) * (M / Q) * (L / P), max);
    }
    cout << max << endl;
    return 0;
}