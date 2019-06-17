#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct S
{
    ll g;
    ll s;
    ll b;
};

ll dp[5][5000 * 5000 + 5];

int main()
{
    ll N;
    cin >> N;

    S sa, sb;
    cin >> sa.g >> sa.s >> sa.b;
    cin >> sb.g >> sb.s >> sb.b;

    ll g = 0, s = 0, b = 0;

    //! 初回A
    {
        memset(dp, 0, sizeof(dp));
        //! ナップザックの価値と重さとみなす
        vector<pll> v; //! (w,v);
        v.push_back(pll(sa.g, sb.g - sa.g));
        v.push_back(pll(sa.s, sb.s - sa.s));
        v.push_back(pll(sa.b, sb.b - sa.b));

        REP(i, 3)
        {
            REP(j, N + 1)
            {
                if (j < v[i].first)
                {
                    dp[i + 1][j] = dp[i][j];
                }
                else
                {
                    dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - v[i].first] + v[i].second);
                }
            }
        }
        N += dp[3][N];
    }

    //! 初回B
    {
        memset(dp, 0, sizeof(dp));
        //! ナップザックの価値と重さとみなす
        vector<pll> v; //! (w,v);
        v.push_back(pll(sb.g, sa.g - sb.g));
        v.push_back(pll(sb.s, sa.s - sb.s));
        v.push_back(pll(sb.b, sa.b - sb.b));

        REP(i, 3)
        {
            REP(j, N + 1)
            {
                if (j < v[i].first)
                {
                    dp[i + 1][j] = dp[i][j];
                }
                else
                {
                    dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - v[i].first] + v[i].second);
                }
            }
        }
        N += dp[3][N];
    }

    cout << N << endl;
    return 0;
}