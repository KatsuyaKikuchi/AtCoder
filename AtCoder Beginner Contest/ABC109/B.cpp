#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string W[105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> W[i];
    }

    string ans = "Yes";
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            if (W[i] != W[j])
                continue;
            ans = "No";
            break;
        }
    }

    FOR(i, N, 1)
    {
        if (W[i][0] != W[i - 1][W[i - 1].length() - 1])
        {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}