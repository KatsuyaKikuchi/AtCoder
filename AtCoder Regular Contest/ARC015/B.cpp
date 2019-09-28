#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int M[10];

int main()
{
    ll N;
    cin >> N;
    memset(M, 0, sizeof(M));
    REP(i, N)
    {
        double a, b;
        cin >> a >> b;
        if (35 <= a)
            M[0]++;
        if (30 <= a && a < 35)
            M[1]++;
        if (25 <= a && a < 30)
            M[2]++;
        if (25 <= b)
            M[3]++;
        if (b < 0 && 0 <= a)
            M[4]++;
        if (a < 0)
            M[5]++;
    }

    REP(i, 6)
    {
        cout << M[i];
        if (i < 5)
            cout << " ";
    }
    cout << endl;
    return 0;
}