#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];

int main()
{
    int N, Q;
    cin >> N >> Q;
    REP(i, N)
    {
        A[i] = 0;
    }
    REP(i, Q)
    {
        ll l, r, t;
        cin >> l >> r >> t;
        --l;
        FOR(j, r, l)
        {
            A[j] = t;
        }
    }
    REP(i, N)
    {
        cout << A[i] << endl;
    }
    return 0;
}