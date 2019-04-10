#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<int> A[20];
ll dp[(1 << 16) + 20];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a].push_back(b);
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    ll num = pow(2, N);
    FOR(i, num, 1)
    {
        ll sum = 0;
        REP(j, N)
        {
            if (((i >> j) & 1) == 0)
                continue;
            bool f = true;
            REP(k, A[j].size())
            {
                if (((i >> A[j][k]) & 1) == 1)
                    f = false;
            }
            if (f)
                sum += dp[i & (~(1 << j))];
        }
        dp[i] = sum;
    }
    cout << dp[num - 1] << endl;
    return 0;
}