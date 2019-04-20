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
    ll sum = 0;
    REP(i, pow(2, N - 1))
    {
        ll s = 0;
        ll n = 0;
        REP(j, N)
        {
            n = n * 10 + (S[j] - '0');
            if (((i >> j) & 1) == 1)
            {
                s += n;
                n = 0;
            }
        }
        sum += s + n;
    }
    cout << sum << endl;
    return 0;
}