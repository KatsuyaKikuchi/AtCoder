#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll M[505][505];

int main()
{
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    memset(M, 0, sizeof(M));
    ll t =1000;
    ll s = -1 * ((h * w - 1) * t + 1);
    for (int i = 1; h * i <= H; ++i)
    {
        for (int j = 1; w * j <= W; ++j)
        {
            M[h * i - 1][w * j - 1] = s;
        }
    }
    REP(i, H)
    {
        REP(j, W)
        {
            if (M[i][j] == 0)
                M[i][j] = t;
        }
    }

    ll sum = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            sum += M[i][j];
        }
    }

    if (sum > 0)
    {
        cout << "Yes" << endl;
        REP(i, H)
        {
            REP(j, W)
            {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "No" << endl;
    return 0;
}