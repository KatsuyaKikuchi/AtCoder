#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

map<string, int> m;

int main()
{
    string S;
    cin >> S;
    int K;
    cin >> K;
    int n = 0;
    REP(i, S.length())
    {
        if (i + K > S.length())
            break;
        string s = "";
        REP(j, K)
        {
            s.push_back(S[i + j]);
        }
        if (m[s]++ == 0)
            n++;
    }
    cout << n << endl;
    return 0;
}