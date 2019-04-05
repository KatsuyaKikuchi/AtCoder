#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[30];

int main()
{
    ll N, X;
    cin >> N >> X;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll sum = 0;
    REP(i, N)
    {
        if (((X >> i) & 1) == 1)
            sum += A[i];
    }
    cout << sum << endl;
    return 0;
}