#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[105], T[105];

int main()
{
    int N, M;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
    }
    cin >> M;
    REP(i, M)
    {
        cin >> T[i];
    }

    int max = 0;
    REP(i, N)
    {
        int n = 0;
        REP(j, N)
        {
            if (S[i] == S[j])
                n++;
        }
        REP(j, M)
        {
            if (S[i] == T[j])
                n--;
        }
        max = std::max(max, n);
    }
    cout << max << endl;
    return 0;
}