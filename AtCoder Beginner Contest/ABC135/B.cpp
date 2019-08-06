#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    ll m = 0;
    REP(i, N)
    {
        if (i + 1 != A[i])
            m++;
    }

    if (m <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}