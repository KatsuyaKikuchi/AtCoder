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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll R = 0, G = 0, B = 0;
    REP(i, N)
    {
        switch (S[i])
        {
        case 'R':
            R++;
            break;
        case 'G':
            G++;
            break;
        case 'B':
            B++;
            break;
        default:
            break;
        }
    }

    cout << R % 2 + G % 2 + B % 2 << endl;
    return 0;
}