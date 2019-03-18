#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int S[100005];

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
        S[a]++;
        S[b]++;
    }

    string ans = "YES";
    REP(i, N)
    {
        if (S[i] % 2 == 1)
            ans = "NO";
    }
    cout << ans << endl;
    return 0;
}