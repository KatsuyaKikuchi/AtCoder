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
    for (int i = S.length() - 1; i > 0; --i)
    {
        if (S[i] == 'A' && S[i - 1] == 'W')
        {
            S[i] = 'C';
            S[i - 1] = 'A';
        }
    }
    cout << S << endl;
    return 0;
}