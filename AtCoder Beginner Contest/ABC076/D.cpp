#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int T[205];
int V[205];

//! [i*0.5秒後に出せる最大速度]
double M[40005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> T[i];
    }
    int t = 0;
    REP(i, N)
    {
        cin >> V[i];
        M[t * 2] = V[i];
        t += T[i];
    }
    FOR(i, t * 2 + 1, 1)
    {
        if (M[i] == 0)
            M[i] = M[i - 1];
    }
    for (int i = t * 2; i > 0; --i)
    {
        M[i] = std::min(M[i], M[i - 1]);
    }
    M[0] = 0;
    FOR(i, t * 2 + 1, 1)
    {
        M[i] = std::min(M[i], M[i - 1] + 0.5);
    }
    M[t * 2] = 0;
    for (int i = t * 2 - 1; i >= 0; --i)
    {
        M[i] = std::min(M[i], M[i + 1] + 0.5);
    }

    double sum = 0;
    REP(i, t * 2)
    {
        sum += 0.25 * (M[i] + M[i + 1]);
    }
    cout << OF64 << sum << endl;
    return 0;
}