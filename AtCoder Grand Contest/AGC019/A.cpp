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
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    ll mins = std::min(S, std::min(2 * H, 4 * Q));
    ll mind = std::min(mins * 2, D);
    cout << (N / 2) * mind + (N % 2) * mins << endl;
    return 0;
}