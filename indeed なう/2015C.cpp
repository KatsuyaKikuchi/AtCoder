#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[5005];
//! i-jで構成されるsubstructが回文か
bool L[5005][5005];
bool U[5005][5005];
//! [i番目までの文字を使った時の]=costの最小値
ll dp[5005];

int N;
string S;

//! i-jで構成されるsubstructが回文か
bool check(int i, int j)
{
    if (U[i][j])
        return L[i][j];
    U[i][j] = true;
    if (i > j)
        return L[i][j] = true;
    if (i == j)
        return L[i][j] = true;
    if (S[i] != S[j])
        return L[i][j] = false;
    return L[i][j] = check(i + 1, j - 1);
}

int main()
{
    cin >> N >> S;
    REP(i, N)
    {
        cin >> C[i];
    }
    REP(i, N)
    {
        FOR(j, N, i)
        {
            check(i, j);
        }
    }
    dp[0] = 0;
    FOR(i, N + 1, 1)
    {
        dp[i] = dp[i - 1] + C[0];
        for (int j = i - 1; j >= 1; --j)
        {
            if (L[j - 1][i - 1])
                dp[i] = std::min(dp[i], dp[j - 1] + C[i - j]);
        }
    }
    cout << dp[N] << endl;
    return 0;
}