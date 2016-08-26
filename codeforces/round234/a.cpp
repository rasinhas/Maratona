#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector <int> ans;
int row[] = {1,2,3,4,6,12};

int main() 
{
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ans.clear();
        for(int i=0;i<6;i++) {
            int ok = 0;
            // testa em cada coluna
            for(int j=0;j<12/row[i];j++) {
                int p = 0;
                for(int k=j;k<12;k+=(12/row[i])) {
                    if(s[k] == 'X') p++;
                }
                if(p == row[i]) ok = 1;
            }
            if(ok) ans.push_back(row[i]);
        }
        cout << ans.size();
        for(int i=0;i<ans.size();i++) cout << " " << ans[i] << "x" << 12/ans[i];
        cout << endl;
    }
    return 0;
}
