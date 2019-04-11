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
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
    }

    int ans = 0;
    REP(i, 9)
    {
        REP(j, N)
        {
            if (S[j][i] == 'o')
            {
                if (j == 0 || S[j - 1][i] != 'o')
                    ans++;
            }
            else if (S[j][i] == 'x')
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}