#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    string s;
    char c[1111];
    while(scanf("%s", c) != EOF ){
        s = c;
        if(s == "brasil") cout << "Feliz Natal!" << endl;
        else if(s == "alemanha") cout << "Frohliche Weihnachten!" << endl;
        else if(s == "austria") cout << "Frohe Weihnacht!" << endl;
        else if(s == "coreia") cout << "Chuk Sung Tan!" << endl;
        else if(s == "espanha") cout << "Feliz Navidad!" << endl;
        else if(s == "grecia") cout << "Kala Christougena!" << endl;
        else if(s == "estados-unidos") cout << "Merry Christmas!" << endl;
        else if(s == "inglaterra") cout << "Merry Christmas!" << endl;
        else if(s == "australia") cout << "Merry Christmas!" << endl;
        else if(s == "portugal") cout << "Feliz Natal!" << endl;
        else if(s == "suecia") cout << "God Jul!" << endl;
        else if(s == "turquia") cout << "Mutlu Noeller" << endl;
        else if(s == "argentina") cout << "Feliz Navidad!" << endl;
        else if(s == "chile") cout << "Feliz Navidad!" << endl;
        else if(s == "mexico") cout << "Feliz Navidad!" << endl;
        else if(s == "antardida") cout << "Merry Christmas!" << endl;
        else if(s == "canada") cout << "Merry Christmas!" << endl;
        else if(s == "irlanda") cout << "Nollaig Shona Dhuit!" << endl;
        else if(s == "belgica") cout << "Zalig Kerstfeest!" << endl;
        else if(s == "italia") cout << "Buon Natale!" << endl;
        else if(s == "libia") cout << "Buon Natale!" << endl;
        else if(s == "siria") cout << "Milad Mubarak!" << endl;
        else if(s == "marrocos") cout << "Milad Mubarak!" << endl;
        else if(s == "japao") cout << "Merii Kurisumasu!" << endl;
        else cout << "--- NOT FOUND ---" << endl;
    }
    return 0;
}

