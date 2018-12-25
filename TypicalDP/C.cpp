#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int R[1050];
//! [i回線まで行った時][人jの]=勝ち残る確率
double dp[15][1050];

double prob(double my, double you)
{
    return 1.0 / (1.0 + pow(10.0, (you - my) / 400.0));
}

int main()
{
    int K;
    cin >> K;
    int N = pow(2, K);
    REP(i, N)
    {
        cin >> R[i];
        dp[0][i] = 1;
    }

    FOR(k, K + 1, 1)
    {
        REP(i, N)
        {
            double p = 0.0;
            int fi = (i / (int)pow(2, k - 1));
            if (fi % 2 == 0)
                fi++;
            else
                fi--;
            fi *= pow(2, k - 1);
            REP(j, pow(2, k - 1))
            {
                p += prob(R[i], R[j + fi]) * dp[k - 1][j + fi];
            }
            dp[k][i] = dp[k - 1][i] * p;
        }
    }

    REP(i, N)
    {
        cout << OF64 << dp[K][i] << endl;
    }
    return 0;
}