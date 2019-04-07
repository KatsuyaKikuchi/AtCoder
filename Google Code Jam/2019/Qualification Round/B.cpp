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
    int T;
    cin >> T;
    REP(t, T)
    {
        ll N;
        cin >> N;
        string S;
        cin >> S;
        string ans = "";
        REP(i, S.length())
        {
            if (S[i] == 'E')
                ans.push_back('S');
            else
                ans.push_back('E');
        }
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
    return 0;
}