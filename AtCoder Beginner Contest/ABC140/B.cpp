#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[5][30];
int main()
{
    ll N;
    cin >> N;
    REP(i, 3)
    {
        REP(j, N)
        {
            cin >> A[i][j];
        }
    }

    ll s = 0;
    REP(i, N)
    {
        s += A[1][i];
        if (i > 0)
        {
            if (A[0][i] == A[0][i - 1] + 1)
            {
                s += A[2][A[0][i - 1] - 1];
            }
        }
    }
    cout << s << endl;
    return 0;
}