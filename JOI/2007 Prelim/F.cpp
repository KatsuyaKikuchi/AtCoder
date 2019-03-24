#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[20][20];

int main()
{
    int A, B;
    cin >> A >> B;
    int N;
    cin >> N;
    REP(i, N)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        C[x][y] = -1;
    }
    C[0][0] = 1;
    REP(i, A)
    {
        REP(j, B)
        {
            if (C[i][j] == -1 || (i == 0 && j == 0))
                continue;
            ll c = 0;
            if (j > 0)
                c += std::max(0LL, C[i][j - 1]);
            if (i > 0)
                c += std::max(0LL, C[i - 1][j]);
            C[i][j] = c;
        }
    }
    cout << C[A - 1][B - 1] << endl;
    return 0;
}