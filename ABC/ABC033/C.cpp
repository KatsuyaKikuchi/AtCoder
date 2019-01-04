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
    string S;
    cin >> S;
    ll k = 1;
    int ans = 0;
    REP(i, S.length())
    {
        if (S[i] == '+')
        {
            if (k > 0)
                ans++;
            k = 1;
        }
        else if (S[i] != '*')
        {
            int t = (int)(S[i] - '0');
            k = std::min((ll)1, k * t);
        }
    }
    if (k > 0)
        ans++;
    cout << ans << endl;
    return 0;
}