#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [Sのi文字目][Tのj文字め]=まで見たときにもっとも長い文字列
int dp[3005][3005];

int main()
{
    string S, T;
    cin >> S >> T;
    REP(i, 3005)
    {
        dp[i][0] = dp[0][i] = 0;
    }

    REP(i, S.length())
    {
        REP(j, T.length())
        {
            dp[i + 1][j + 1] = dp[i][j];
            if (T[j] == S[i])
            {
                dp[i + 1][j + 1] += 1;
            }

            if (dp[i + 1][j + 1] < dp[i + 1][j])
                dp[i + 1][j + 1] = dp[i + 1][j];
            if (dp[i + 1][j + 1] < dp[i][j + 1])
                dp[i + 1][j + 1] = dp[i][j + 1];
        }
    }

    string a = "";
    int ls = S.length(), lt = T.length();
    while (dp[ls][lt] > 0)
    {
        if (S[ls - 1] == T[lt - 1])
        {
            a = S[ls-1] + a;
            ls--;
            lt--;
        }
        else if (dp[ls - 1][lt] >= dp[ls][lt - 1])
        {
            ls--;
        }
        else
        {
            lt--;
        }
    }
    cout << a << endl;
    return 0;
}