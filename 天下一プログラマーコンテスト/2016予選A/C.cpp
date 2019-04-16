#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Vertex
{
    int parCnt = 0;
    bool use = false;
    bool child[30];
};

Vertex V[30];

int main()
{
    int N;
    cin >> N;

    bool error = false;
    REP(i, N)
    {
        string A, B;
        cin >> A >> B;
        bool e = false;
        REP(j, std::min(A.length(), B.length()))
        {
            if (A[j] != B[j])
            {
                e = true;
                int a = A[j] - 'a', b = B[j] - 'a';
                if (!V[a].child[b])
                {
                    V[a].child[b] = true;
                    V[b].parCnt++;
                }
                break;
            }
        }
        if (!e)
        {
            if (A.length() > B.length())
                error = true;
        }
    }

    string ans = "";
    REP(i, 26)
    {
        REP(j, 26)
        {
            if (V[j].use || V[j].parCnt != 0)
                continue;
            V[j].use = true;
            ans.push_back('a' + j);
            REP(k, 26)
            {
                if (V[j].child[k])
                    V[k].parCnt--;
            }
            break;
        }
    }
    if (ans.length() < 26)
        error = true;
    if (error)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}