#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[30], B[30];

int main()
{
    int N, M;
    cin >> N >> M;
    string X, Y;
    cin >> X >> Y;
    REP(i, N)
    {
        A[X[i] - 'A']++;
    }
    REP(i, M)
    {
        B[Y[i] - 'A']++;
    }

    ll min = 0;
    REP(i, 26)
    {
        if (B[i] == 0)
        {
            if (A[i] == 0)
                continue;
            min = -1;
            break;
        }
        min = std::max(min, (A[i] + B[i] - 1) / B[i]);
    }
    cout << min << endl;
    return 0;
}