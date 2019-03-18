#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    int N, x;
    cin >> N >> x;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll n = 0;
    FOR(i, N, 1)
    {
        if (A[i] + A[i - 1] <= x)
            continue;
        ll t = (A[i] + A[i - 1]) - x;

        n += t;
        A[i] -= std::min(t, A[i]);
    }
    cout << n << endl;
    return 0;
}