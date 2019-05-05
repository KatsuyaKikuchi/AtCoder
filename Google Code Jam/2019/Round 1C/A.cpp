#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char B[3] = {'R', 'S', 'P'};

int main()
{
    int T;
    cin >> T;
    REP(cs, T)
    {
        int A;
        cin >> A;
        vector<string> C;
        REP(i, A)
        {
            string c;
            cin >> c;
            C.push_back(c);
        }
        string ans = "";

        bool e = true;
        REP(i, 505)
        {
            if (C.size() == 0)
                break;
            int bit = 7;
            REP(j, C.size())
            {
                int l = C[j].length();
                REP(b, 3)
                {
                    if (C[j][i % l] == B[b])
                        bit &= ~(1 << ((b + 1) % 3));
                }
            }
            if (bit == 0)
            {
                e = false;
                break;
            }
            vector<string> T;
            char c;
            REP(j, 3)
            {
                if (((bit >> j) & 1) == 1 && ((bit >> ((2 + j) % 3)) & 1) == 0)
                {
                    c = B[j];
                    break;
                }
            }
            REP(j, C.size())
            {
                int l = C[j].length();
                if (C[j][i % l] == c)
                    T.push_back(C[j]);
            }
            ans.push_back(c);
            swap(T, C);
        }
        cout << "Case #" << cs + 1 << ": ";
        if (e)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}