#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    string S;
    cin >> S;
    int joi = 0, ioi = 0;
    REP(i, S.length() - 2)
    {
        if (S[i + 1] != 'O' || S[i + 2] != 'I')
            continue;
        if (S[i] == 'J')
            joi++;
        else if (S[i] == 'I')
            ioi++;
    }
    cout << joi << endl;
    cout << ioi << endl;
    return 0;
}