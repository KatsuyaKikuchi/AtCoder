#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[3005];
ll S[3005];

int main()
{
    int N;
    cin >> N;
    S[0] = 0;
    REP(i, N)
    {
        cin >> A[i];
        S[i + 1] = S[i] + A[i];
    }

    FOR(i, N + 1, 1)
    {
        ll max = 0;
        REP(j, N)
        {
            if (i + j > N)
                break;
            max = std::max(max, S[i + j] - S[j]);
        }
        cout << max << endl;
    }
    return 0;
}