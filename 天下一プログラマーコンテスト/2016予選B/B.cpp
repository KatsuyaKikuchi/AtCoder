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
    int N = S.length();
    int s = 0;
    int m = 0;
    int ans = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (S[i] == ')')
            s++;
        else
            s--;

        if (s < 0)
        {
            s += 2;
            ans++;
            m = std::max(m, i);
        }
        else if (s > i)
        {
            s -= 2;
            ans++;
            m = std::max(m, i);
        }
    }
    cout << ans + m << endl;
    return 0;
}
