#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int rel[111111];
vector <string> cmd;

void apply(int n)
{
    long long s[1111];
    int t=0;
    s[t] = n;
    for(int i=0;i<cmd.size();i++)
    {
        if(cmd[i] == "NUM") s[++t] = rel[i];
        else
        {
            if(t == -1) 
            {
                cout << "ERROR" << endl;
                return;
            }
            else 
            {
                if(cmd[i] == "POP") t--;
                else if(cmd[i] == "INV") s[t] *= -1;
                else if(cmd[i] == "DUP") s[t+1] = s[t++];
                else
                {
                    if(t == 0) 
                    {
                        cout << "ERROR" << endl;
                        return;
                    }
                    else
                    {
                        if(cmd[i] == "SWP") swap(s[t],s[t-1]);
                        else if(cmd[i] == "ADD") s[t-1] = s[t-1]+s[t--];
                        else if(cmd[i] == "SUB") s[t-1] = s[t-1]-s[t--];
                        else if(cmd[i] == "MUL") s[t-1] = s[t-1]*s[t--];
                        else 
                        {
                            if(s[t] == 0) 
                            {
                                cout << "ERROR" << endl;
                                return;
                            }
                            else 
                            {
                                if(cmd[i] == "DIV") s[t-1] = s[t-1]/s[t--];
                                else if(cmd[i] == "MOD") s[t-1] = s[t-1]%s[t--];
                            }
                        }
                    }
                }
            }
        }
        if(t >= 0 && (s[t] > 1e9 || s[t] < -1e9)) 
        {
            cout << "ERROR" << endl;
            return;
        }
    }
    if(t != 0) cout << "ERROR" << endl;
    else cout << s[t] << endl;
}

int main()
{
    string c;
    int p=0;
    while(cin >> c)
    {
        if(c == "QUIT") break;
        else if(c != "END")
        {
            cmd.push_back(c);
            if(c == "NUM") cin >> rel[p];
            p++;
        }
        else 
        {
            int n, q;
            cin >> n;
            for(int i=0;i<n;i++)
            {
                cin >> q;
                apply(q);
            }
            cmd.clear();
            p = 0;
            cout << endl;
        }
    }
    return 0;
}
