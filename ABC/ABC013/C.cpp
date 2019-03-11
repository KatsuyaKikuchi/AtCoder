#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, H, A, B, C, D, E;
//! コストnでN日間生きられるか
bool check(ll n)
{
    ll max = 0;
    REP(i, N + 1)
    {
        //! CDをi回行う
        if (C * i > n)
            break;

        ll j = (n - C * i) / A;
        max = std::max(max, (B + E) * j + (D + E) * i);
    }
    return H + max - N * E > 0;
}
int main()
{
    cin >> N >> H >> A >> B >> C >> D >> E;

    ll ok = A * N, ng = -1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}