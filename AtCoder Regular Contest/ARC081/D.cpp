#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[2];

int main()
{
    ll N;
    cin >> N;
    REP(i, 2)
    {
        cin >> S[i];
    }

    ll ans = 1;
    REP(i, N)
    {
        if (S[0][i] == S[1][i])
        {
            if (i == 0)
                ans = 3;
            else if (S[0][i - 1] == S[1][i - 1])
                ans *= 2;
        }
        else
        {
            if (i == 0)
                ans = 6;
            else
            {
                if (S[0][i - 1] == S[1][i - 1])
                    ans *= 2;
                else
                    ans *= 3;
            }
            ++i;
        }
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}