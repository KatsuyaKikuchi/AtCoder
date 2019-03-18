#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[110];
int main()
{
    int H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> M[i + 1];
    }
    REP(i, H + 2)
    {
        REP(j, W + 2)
        {
            if (i == 0 || i == H + 1 || j == 0 || j == W + 1)
                cout << "#";
            else
                cout << M[i][j - 1];
        }
        cout << endl;
    }
    return 0;
}