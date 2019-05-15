#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[1000005];

int main()
{
    int N;
    cin >> N;
    memset(T, 0, sizeof(T));
    REP(i, N)
    {
        int s, t;
        cin >> s >> t;
        T[s]++;
        T[t]--;
    }
    int n = 0;
    FOR(i, 1000005, 1)
    {
        T[i] += T[i - 1];
        if (T[i - 1] == 0 && T[i] > 0)
            n++;
    }
    cout << n << endl;
    return 0;
}