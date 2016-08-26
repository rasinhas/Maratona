#include <iostream>
#include <cstdio>

using namespace std;

int m[444][444], pos[444][444], neg[444][444];

int main()
{
    int n, ans=0, b;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> m[i][j];
    //for(int i=0;i<n;i++) for(int j=0;j<n;j++) ma[i][j] = ma[i][n-j-1];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) pos[i+1][j+1] = pos[i][j] + m[i][j];
    //for(int i=0;i<n;i++) for(int j=0;j<n;j++) neg[i+1][j+1] = neg[i][j] + ma[i][j];
    for(int i=0;i<n;i++) for(int j=0;k<n;j) for(int k=0;k<=min(n-i-1,n-j-1);k++) neg[i+1][j+1] += m[i+k][n-j-1-k];
    for(int i=0;i<=n;i++) for(int k=0;k<=n-i;k++) for(int j=0;j<=n-k;j++) ans = max(ans,(pos[i+k][j+k]-pos[i][j])-(neg[i+k][j+k]-neg[i][j]));
    cout << ans << endl;
    return 0;
}
