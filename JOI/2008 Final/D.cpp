#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<pll> S[160];
//! [i行目][j番目の石まで][k回の飛ばしジャンプを使って]=行く危険度最小値
ll dp[160][15][80];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, N)
    {
        int k;
        cin >> k;
        REP(j, k)
        {
            pll x;
            cin >> x.first >> x.second;
            x.first--;
            S[i].push_back(x);
        }
    }
    REP(i, N)
    {
        REP(j, S[i].size())
        {
            REP(k, M + 1)
            {
                ll min = INF;
                //! 通常ジャンプで来る
                if (i - 1 < 0)
                    min = 0;
                else
                {
                    REP(l, S[i - 1].size())
                    {
                        ll c = dp[i - 1][l][k] + abs(S[i - 1][l].first - S[i][j].first) * (S[i - 1][l].second + S[i][j].second);
                        min = std::min(min, c);
                    }
                }
                //! 飛ばしジャンプで来る
                if (k > 0)
                {
                    if (i - 2 < 0)
                        min = 0;
                    else
                    {
                        REP(l, S[i - 2].size())
                        {
                            ll c = dp[i - 2][l][k - 1] + abs(S[i - 2][l].first - S[i][j].first) * (S[i - 2][l].second + S[i][j].second);
                            min = std::min(min, c);
                        }
                    }
                }
                dp[i][j][k] = min;
            }
        }
    }

    ll ans = INF;
    REP(m, M + 1)
    {
        REP(i, S[N - 1].size())
        {
            ans = std::min(ans, dp[N - 1][i][m]);
        }
        if (N >= 2 && m < M)
        {
            REP(i, S[N - 2].size())
            {
                ans = std::min(ans, dp[N - 2][i][m]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}