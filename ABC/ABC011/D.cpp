#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

double M[2][1005][1005];
int h[4] = {0, 1, 0, -1};
int w[4] = {1, 0, -1, 0};

int main()
{
    ll N, D, X, Y;
    cin >> N >> D >> X >> Y;
    if (abs(X) % D != 0 || abs(Y) % D != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll x = abs(X) / D, y = abs(Y) / D;
    M[0][0][0] = 1.0;
    FOR(i, N + 1, 1)
    {
        REP(j, i + 1)
        {
            REP(k, i + 1)
            {
                if (j + k > i || j + k > 100)
                    break;
                M[i % 2][j][k] = 0.0;
                REP(l, 4)
                {
                    M[i % 2][j][k] += M[(i + 1) % 2][abs(j + h[l])][abs(k + w[l])] * 0.25;
                }
            }
        }
    }
    cout << OF64 << M[N % 2][x][y] << endl;
    return 0;
}