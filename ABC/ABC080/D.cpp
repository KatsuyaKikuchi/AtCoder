#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[100005][35];
ll S[100005];

int main()
{
    int N, C;
    cin >> N >> C;
    REP(i, N)
    {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        T[s][c]++;
        T[t][c]--;
    }
    ll max = 0;
    REP(i, 100005)
    {
        REP(j, C)
        {
            if (T[i][j] > 0)
                S[i - 1]++;
            else if (T[i][j] < 0)
                S[i]--;
        }
        if (i > 0)
            S[i] += S[i - 1];
    }
    REP(i, 100005)
    {
        max = std::max(max, S[i]);
    }
    cout << max << endl;
    return 0;
}