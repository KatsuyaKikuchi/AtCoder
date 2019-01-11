#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N[10005];
int T, B;

string binary(ll n)
{
    if (n == 0)
        return "0";
    string s = "";
    while (abs(n) > 0)
    {
        int t = n / B;
        int k = n - t * B;
        if (k < 0)
            k += abs(B);
        s += (char)('0' + k);
        n = (n - k) / B;
    }
    std::reverse(s.begin(), s.end());
    return s;
}
int main()
{
    cin >> T >> B;
    REP(i, T)
    {
        cin >> N[i];
    }
    REP(i, T)
    {
        cout << binary(N[i]) << endl;
    }
    return 0;
}