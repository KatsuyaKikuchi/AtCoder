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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    REP(i, N)
    {
        if (i == K - 1)
        {
            if (S[i] == 'A')
                cout << 'a';
            else if (S[i] == 'B')
                cout << 'b';
            else
                cout << 'c';
        }
        else
        {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}