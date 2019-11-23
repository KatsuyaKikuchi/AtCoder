#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[305];
ll dp[305][305][305];
ll m[305][305];
ll up[305];

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> v;
    REP(i, N)
    {
        cin >> H[i];
        v.push_back(H[i]);
    }
    if (N == K)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    REP(i, N + 1)
    {
        REP(j, K + 1)
        {
            REP(k, v.size())
            {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    REP(i, K + 1)
    {
        REP(j, v.size())
        {
            m[i][j] = v[j];
        }
    }

    REP(i, N)
    {
        REP(j, K + 1)
        {
            //   cout << "cost : ";
            REP(k, v.size())
            {
                if (v[k] == H[i])
                {
                    //! 変化なし
                    dp[i + 1][j][k] = std::min(m[j][k], dp[i + 1][j][k]);
                }
                else
                {
                    dp[i + 1][j + 1][k] = std::min(dp[i + 1][j + 1][k], m[j][k]);
                }
                //     cout << dp[i + 1][j][k] << " ";
            }
            // cout << endl;
        }
        REP(j, K + 1)
        {
            vector<ll> u(v.size()), d(v.size());
            REP(k, v.size())
            {
                if (k > 0)
                    u[k] = std::min(-v[k] + dp[i + 1][j][k], u[k - 1]);
                else
                    u[k] = -v[k] + dp[i + 1][j][k];
            }
            for (int k = v.size() - 1; k >= 0; k--)
            {
                if (k < v.size() - 1)
                    d[k] = std::min(dp[i + 1][j][k], d[k + 1]);
                else
                    d[k] = dp[i + 1][j][k];
            }

            //  cout << j << ":";
            REP(k, v.size())
            {
                m[j][k] = std::min(v[k] + u[k], d[k]);
                //  cout << m[j][k] << " ";
            }
            // cout << endl;
        }
    }

    ll min = INF;
    REP(i, K + 1)
    {
        REP(j, v.size())
        {
            min = std::min(min, dp[N][i][j]);
        }
    }
    cout << min << endl;
    return 0;
}