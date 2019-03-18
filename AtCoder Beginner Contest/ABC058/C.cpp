#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[55];
int C[30];
int main()
{
    int N;
    cin >> N;
    REP(i, 30)
    {
        C[i] = 1000;
    }
    REP(i, N)
    {
        cin >> S[i];
        int K[30] = {0};
        REP(j, S[i].length())
        {
            K[S[i][j] - 'a']++;
        }
        REP(j, 30)
        {
            C[j] = std::min(K[j], C[j]);
        }
    }

    string A = "";
    REP(i, 30)
    {
        REP(j, C[i])
        {
            A += (char)('a' + i);
        }
    }
    cout << A << endl;
    return 0;
}