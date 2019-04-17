#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int M[35][35];
//! hasimotoくんがi番目の選手をj回勝ったと記録する確率
double dp[35][35][35];
//! [i位の選手が][j勝するような]=確率
double A[35][35];

int main()
{
    int N;
    string S;
    cin >> N >> S;
    double p = 10, q = 10;
    if (S.length() == 3)
    {
        p = S[0] - '0';
        q = S[2] - '0';
    }
    else if (S.length() == 4)
        p = S[0] - '0';
    double P = p / q;
    vector<pll> v;
    REP(i, N)
    {
        pll n(i, 0);
        REP(j, N)
        {
            cin >> M[i][j];
            n.second += M[i][j];
        }
        v.push_back(n);
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.second == b.second ? a.first < b.first : a.second > b.second; });
    memset(dp, 0, sizeof(dp));
    REP(i, N)
    {
        dp[i][0][0] = 1;
        REP(j, N)
        {
            for (int k = 0; k <= j + 1; ++k)
            {
                if (i == j)
                {
                    dp[i][j + 1][k] = dp[i][j][k];
                    continue;
                }
                double p = 0;
                if (k > 0)
                    p = dp[i][j][k - 1];
                if (M[i][j] == 0)
                    dp[i][j + 1][k] = P * dp[i][j][k] + (1 - P) * p;
                else
                    dp[i][j + 1][k] = (1 - P) * dp[i][j][k] + P * p;
            }
        }
    }
    memset(A, 0, sizeof(A));
    for (int i = N - 1; i >= 0; --i)
    {
        int x = v[i].first;
        if (i == N - 1)
        {
            REP(j, N)
            {
                A[i][j] = dp[x][N][j];
            }
            continue;
        }
        int y = v[i + 1].first;
        REP(j, N)
        {
            double sum = 0;
            REP(k, j + 1)
            {
                if (x > y && j == k)
                    break;
                sum += A[i + 1][k];
            }
            A[i][j] = sum * dp[x][N][j];
        }
    }

    double ans = 0;
    REP(i, N)
    {
        ans += A[0][i];
    }
    cout << OF64 << ans << endl;
    return 0;
}