#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int W[2005][2005];
int B[2005][2005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, 2 * K + 1)
    {
        REP(j, 2 * K + 1)
        {
            B[i][j] = W[i][j] = 0;
        }
    }
    REP(i, N)
    {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        x %= (2 * K);
        y %= (2 * K);
        if (c == 'B')
            B[x + 1][y + 1]++;
        else
            W[x + 1][y + 1]++;
    }

    FOR(i, 2 * K + 1, 1)
    {
        FOR(j, 2 * K + 1, 1)
        {
            B[i][j] += B[i][j - 1];
            W[i][j] += W[i][j - 1];
        }
    }
    FOR(i, 2 * K + 1, 1)
    {
        FOR(j, 2 * K + 1, 1)
        {
            B[j][i] += B[j - 1][i];
            W[j][i] += W[j - 1][i];
        }
    }

    int max = 0;
    REP(i, K)
    {
        REP(j, K)
        {
            //! (0,0)にWの(i,j)を置いた際に叶えられる最大値
            int w = (W[2 * K - i][2 * K] - W[K - i][2 * K]) + (W[2 * K][2 * K - j] - W[2 * K][K - j]) - 2 * (W[2 * K - i][2 * K - j] - W[2 * K - i][K - j] - W[K - i][2 * K - j] + W[K - i][K - j]);
            int b = (B[2 * K - i][2 * K] - B[K - i][2 * K]) + (B[2 * K][2 * K - j] - B[2 * K][K - j]) - 2 * (B[2 * K - i][2 * K - j] - B[2 * K - i][K - j] - B[K - i][2 * K - j] + B[K - i][K - j]);
            //! K-i<=x%2*K<=2*K-1-i && K-j<=y%2*K<=2*K-1-jの部分は黒
            max = std::max(max, W[2 * K][2 * K] - w + b);

            //! (0,0)にBの(i,j)を置いた際に叶えられる最大値
            max = std::max(max, w + B[2 * K][2 * K] - b);
        }
    }
    cout << max << endl;
    return 0;
}