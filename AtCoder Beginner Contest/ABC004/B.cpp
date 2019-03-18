#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[5][5];

int main()
{
    REP(i, 4)
    {
        REP(j, 4)
        {
            cin >> C[i][j];
        }
    }

    for (int i = 3; i >= 0; --i)
    {
        for (int j = 3; j >= 0; --j)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}