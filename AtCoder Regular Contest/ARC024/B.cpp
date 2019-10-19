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
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    int max = 0;
    int m = 1;
    REP(i, N - 1)
    {
        if (A[i] != A[i + 1])
            m = 0;
        max = std::max(++m, max);
    }
    REP(i, N)
    {
        int n = (N - 1 + i) % N;
        if (A[n] != A[(n + 1) % N])
            break;
        max = std::max(max, ++m);
    }

    if (max >= N)
        cout << -1 << endl;
    else
        cout << (max - 1) / 2 + 1 << endl;

    return 0;
}