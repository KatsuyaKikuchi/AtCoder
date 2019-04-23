#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[100005];
ll A[100005];

ll X[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> T[i];
    }
    REP(i, N)
    {
        cin >> A[i];
    }
    bool exist = true;
    REP(i, N)
    {
        if (i == 0 || T[i - 1] < T[i])
        {
            X[i] = 1;
            if (T[i] > A[i])
                exist = false;
        }
        else
        {
            X[i] = T[i];
        }
    }
    for (int i = N - 1; i >= 0; --i)
    {
        if (i == N - 1 || A[i] > A[i + 1])
        {
            X[i] = 1;
            if (A[i] > T[i])
                exist = false;
        }
        else
        {
            X[i] = std::min(X[i], A[i]);
        }
    }

    ll ans = exist ? 1 : 0;
    REP(i, N)
    {
        ans = (ans * X[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}