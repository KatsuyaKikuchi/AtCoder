#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[100005];

int main()
{
    ll N;
    cin >> N;
    ll s = 0;
    ll a = 0, b = 0, ab = 0;
    REP(i, N)
    {
        cin >> S[i];
        int n = S[i].length();
        REP(j, n - 1)
        {
            if (S[i][j] == 'A' && S[i][j + 1] == 'B')
                s++;
        }
        if (S[i][0] == 'B' && S[i][n - 1] == 'A')
            ab++;
        else if (S[i][0] == 'B')
            b++;
        else if (S[i][n - 1] == 'A')
            a++;
    }
    if (ab > 0)
    {
        s += ab - 1;
        if (a > 0)
        {
            s++;
            a--;
        }
        if (b > 0)
        {
            b--;
            s++;
        }
    }
    s += std::min(a, b);

    cout << s << endl;
    return 0;
}