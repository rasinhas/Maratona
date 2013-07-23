#include <iostream>
#include <string>

using namespace std;

int r[8] = {0,0,1,7,4,2,6,8};

int main()
{
    int t, n;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        s = "";
        int m = n;
        if(m < 8) cout << r[m];
        else
        {
            if(m%7 == 1) cout << "10";
            if(m%7 == 2) cout << "18";
            if(m%7 == 3)
            {
                if(m/7 > 1)
                {
                    cout << "200";
                    m-=7;
                }
                else cout << "22";
            }
            if(m%7 == 4) cout << "20";
            if(m%7 == 5) cout << "28";
            if(m%7 == 6) cout << "68";
            if(m%7 == 0) cout << "8";
            for(int i=0;i<(m/7)-1;i++) cout << 8;
        }
        cout << " ";
        if(n%2 == 1)
        {
            cout << 7;
            n -= 1;
        }
        else cout << 1;
        for(int i=0;i<(n/2)-1;i++) cout << 1;
        cout << endl;
    }
    return 0;
}
