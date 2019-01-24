#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[300];

int main()
{
    int N;
    cin >> N;
    REP(i, 2 * N)
    {
        cin >> L[i];
    }
    sort(L, L + 2 * N);
    ll sum = 0;
    REP(i, N)
    {
        sum += L[2 * i];
    }
    cout << sum << endl;
    return 0;
}