#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N;
int D[105];

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> D[i];
    }
    sort(D, D + N);
    int m = D[0];
    int n = 1;
    REP(i, N)
    {
        if (m == D[i])
            continue;
        m = D[i];
        n++;
    }
    cout << n << endl;
    return 0;
}