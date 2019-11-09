#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int N;
    string A, B, C;
    cin >> N;
    cin >> A >> B >> C;
    int ans = 0;
    REP(i, N)
    {
        if (A[i] == B[i])
        {
            if (A[i] != C[i])
                ans++;
        }
        else if (B[i] == C[i])
        {
            if (B[i] != A[i])
                ans++;
        }
        else if (C[i] == A[i])
        {
            if (A[i] != B[i])
                ans++;
        }
        else
        {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}