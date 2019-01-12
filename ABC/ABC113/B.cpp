#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll K[1005];

int main()
{
    int N, T, A;
    cin >> N >> T >> A;
    int mini = 0;
    A *= 1000;
    REP(i, N)
    {
        ll h;
        cin >> h;
        K[i] = T * 1000 - h * 6;
        if (abs(A - K[i]) < abs(A - K[mini]))
            mini = i;
    }
    cout << mini + 1 << endl;
    return 0;
}