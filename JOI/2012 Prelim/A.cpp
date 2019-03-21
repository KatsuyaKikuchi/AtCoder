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
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    cout << L - std::max((A + C - 1) / C, (B + D - 1) / D) << endl;
    return 0;
}