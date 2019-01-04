#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[110];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i + 1];
    }

    int m = 1;
    int pi = 0;
    REP(i, N + 2)
    {
        if (A[i] == 1)
            continue;

        m = std::max(m, (int)i - pi);
        pi = i;
    }
    cout << m << endl;
    return 0;
}