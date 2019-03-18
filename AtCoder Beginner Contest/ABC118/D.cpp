#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int K[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

int A[15];
//! マッチをn本使った時の文字列の最大長
int dp[10005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> A[i];
        A[i]--;
    }

    sort(A, A + M, [](int a, int b) { return K[a] == K[b] ? a > b : K[a] < K[b]; });
    vector<int> t;

    dp[0] = 0;
    REP(i, M)
    {
        dp[K[A[i]]] = 1;
    }
    FOR(i, N + 1, 2)
    {
        int m = dp[i];
        REP(j, M)
        {
            if (i - K[A[j]] < 0)
                continue;
            if (dp[i - K[A[j]]] == 0)
                continue;
            m = std::max(dp[i - K[A[j]]] + 1, m);
        }
        dp[i] = m;
    }
    //! dp復元
    int p = N;
    while (p > 0)
    {
        int max = 0;
        int np = p;
        REP(i, M)
        {
            if (dp[p] - 1 != dp[p - K[A[i]]])
                continue;
            if (dp[p] == 1 && p - K[A[i]] != 0)
                continue;
            if (max < A[i] + 1)
            {
                max = A[i] + 1;
                np = p - K[A[i]];
            }
        }
        t.push_back(max);
        p = np;
    }

    sort(t.begin(), t.end(), [](int a, int b) { return a > b; });
    REP(i, t.size())
    {
        cout << t[i];
    }
    cout << endl;
    return 0;
}