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
    int N;
    cin >> N;
    ll ans = 0;
    REP(i, N)
    {
        string T;
        cin >> T;
        REP(i, T.length())
        {
            bool same = true;
            REP(j, S.length())
            {
                if (T[(i + j) % T.length()] == S[j])
                    continue;
                same = false;
                break;
            }
            if (same)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}