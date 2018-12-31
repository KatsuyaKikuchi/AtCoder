#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[55];

int main()
{
    int N;
    cin>>N;
    REP(i, N)
    {
        cin >> M[i];
    }
    REP(i, N)
    {
        REP(j, N)
        {
            cout << M[N - j - 1][i];
        }
        cout << endl;
    }
    return 0;
}