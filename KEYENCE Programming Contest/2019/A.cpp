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
    int N[4];
    REP(i, 4)
    {
        cin >> N[i];
    }
    sort(N, N + 4);
    if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}