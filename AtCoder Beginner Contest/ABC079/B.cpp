#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[100];

int main()
{
    int N;
    cin >> N;
    L[0] = 2;
    L[1] = 1;
    FOR(i, 100, 2)
    {
        L[i] = L[i - 1] + L[i - 2];
    }
    cout << L[N] << endl;
    return 0;
}