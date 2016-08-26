#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) != EOF) {
        if(a && b && !c) cout << "C" << endl;
        else if(a && !b && c) cout << "B" << endl;
        else if(!a && b && c) cout << "A" << endl;
        else if(a && !b && !c) cout << "A" << endl;
        else if(!a && b && !c) cout << "B" << endl;
        else if(!a && !b && c) cout << "C" << endl;
        else cout << "*" << endl;
    }
    return 0;
}
