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
    int T;
    cin >> T;
    REP(t, T)
    {
        string N;
        cin >> N;
        string A = "", B = "";
        for (int i = N.size() - 1; i >= 0; --i)
        {
            if (N[i] == '4')
            {
                A.push_back('3');
                B.push_back('1');
            }
            else
            {
                A.push_back(N[i]);
                B.push_back('0');
            }
        }
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());

        while (B[0] == '0')
            B.erase(B.begin());

        cout << "Case #" << t + 1 << ": " << A << " " << B << endl;
    }
    return 0;
}