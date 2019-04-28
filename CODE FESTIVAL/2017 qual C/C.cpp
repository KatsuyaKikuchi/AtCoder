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
    int f = 0, l = S.length() - 1;
    int ans = 0;
    while (f <= l)
    {
        if (S[f] == S[l])
        {
            f++;
            l--;
            continue;
        }
        if (S[f] == 'x')
        {
            f++;
            ans++;
            continue;
        }
        else if (S[l] == 'x')
        {
            l--;
            ans++;
            continue;
        }
        ans = -1;
        break;
    }
    cout << ans << endl;
    return 0;
}