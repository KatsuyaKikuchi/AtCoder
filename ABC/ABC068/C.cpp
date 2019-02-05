#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool X[200005];
bool Y[200005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == 0)
            X[b] = true;
        if (b == N - 1)
            Y[a] = true;
    }

    string ans = "IMPOSSIBLE";
    REP(i, N)
    {
        if (X[i] && Y[i])
        {
            ans = "POSSIBLE";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}