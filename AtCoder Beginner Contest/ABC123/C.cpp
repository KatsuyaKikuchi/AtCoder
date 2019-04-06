#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[10];

int main()
{
    ll N;
    cin >> N;
    ll min = INF;
    REP(i, 5)
    {
        ll a;
        cin >> a;
        min = std::min(a, min);
    }

    cout << 4LL + (N + min - 1) / min << endl;
    return 0;
}