
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main()
{
    optimizeIO();

//    freopen("in1.txt","r",stdin);
//    freopen("out0.txt","w",stdout);

//    RBT r;

    map<int,int>m;

    string option;

    while(cin>>option)
    {
        int num;
        cin>>num;

        if(option=="F")
        {
            if(m.count(num))
            {

            }
//                cout<<"True"<<endl;
            else
            {

            }
//                cout<<"False"<<endl;
        }
        else if(option=="I")
        {
            m.insert({num,1});
        }
        else if(option=="D")
        {
            m.erase(num);
        }
    }

    #ifndef ONLINE_JUDGE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}
