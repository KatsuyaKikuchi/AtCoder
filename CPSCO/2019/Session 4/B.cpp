#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[105];

int main()
{
    int N, D;
    cin >> N >> D;
    REP(i, D)
    {
        cin >> S[i];
    }

    ll max = 0;
    REP(i, D)
    {
        REP(j, D)
        {
            ll m = 0;
            REP(k, N)
            {
                if (S[i][k] == 'o' || S[j][k] == 'o')
                    m++;
            }
            max = std::max(max, m);
        }
    }
    cout << max << endl;
    return 0;
}