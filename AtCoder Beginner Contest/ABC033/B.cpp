#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[2005];
int P[2005];

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    REP(i, N)
    {
        cin >> S[i] >> P[i];
        sum += P[i];
    }
    string s = "atcoder";
    REP(i, N)
    {
        if (sum / 2 + 1 <= P[i])
            s = S[i];
    }
    cout << s << endl;
    return 0;
}