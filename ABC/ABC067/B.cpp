#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int L[55];

int main()
{
    int N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> L[i];
    }
    sort(L, L + N, [](int a, int b) { return a > b; });
    int S = 0;
    REP(i, K)
    {
        S += L[i];
    }
    cout << S << endl;
    return 0;
}