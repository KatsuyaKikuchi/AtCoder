#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N[30];

int main()
{
    string S;
    cin >> S;
    memset(N, 0, sizeof(N));
    REP(i, S.length())
    {
        N[S[i] - 'a']++;
    }

    int n = 0;
    REP(i, 26)
    {
        n = std::max(n, N[i]);
    }
    string ans = "Yes";
    REP(i, 26)
    {
        if (N[i] == 0)
            continue;
        if (N[i] != n)
            ans = "No";
    }
    cout << ans << endl;
    return 0;
}