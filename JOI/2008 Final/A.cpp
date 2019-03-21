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
    int N;
    cin >> N;
    stack<int> b, w;
    int wn = 0;
    REP(i, N)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            if (w.empty())
            {
                w.push(-1);
            }
            if (w.top() == i - 1)
            {
                w.pop();
                w.push(i);
            }
            else
            {
                if (i % 2 == 1)
                {
                    wn += i - w.top() - 1;
                    w.pop();
                    b.pop();
                }
                w.push(i);
            }
            wn++;
        }
        else
        {
            if (b.empty())
            {
                b.push(-1);
            }
            if (b.top() == i - 1)
            {
                b.pop();
                b.push(i);
            }
            else
            {
                if (i % 2 == 1)
                {
                    wn -= i - b.top() - 1;
                    b.pop();
                    w.pop();
                }
                b.push(i);
            }
        }
        //cout<<i<<":"<<wn<<endl;
    }
    cout << wn << endl;
    return 0;
}