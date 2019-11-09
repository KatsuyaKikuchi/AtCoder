#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll B[100005];

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;

    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        cin >> B[i];
    }
    string ans = "Same";
    if (N == M)
    {
        REP(i, std::max(N, M))
        {
            if (A[i] == B[i])
                continue;
            if (A[i] < B[i])
                ans = "X";
            else if (A[i] > B[i])
                ans = "Y";
            break;
        }
    }
    else
    {
        if (N > M)
            ans = "Y";
        else
            ans = "X";
    }

    cout << ans << endl;
    return 0;
}