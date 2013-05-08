#include <iostream>
#include <cstdio> 
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Solução com o trie otimizado da UFRGS -- melhorou bastante a memória e em cerca de 33% o tempo de execução no meu caso
// (comparando com o do avelino, so melhorou a memória)
// Solução impede fazer 26 operações por nivel, mas é bastante complicado de se manipular.

bool comp(const string &a, const string &b)
{ return a.size() < b.size(); }

string s;
long long last[30];
int size;

long long ret;

struct node
{
    char c, end;
    int out;
    node *right;
    node *down;
    node *fail;

    node(char val=' ') : c(val), right(NULL), down(NULL), out(0), end(0) {}

    void insert(int p, int sum=0)
    {
        if (s[p] == c)
        {
            if (p == s.size()-1)
            {
                end = 1;
                out = max(out, sum+1); return;
            }
            if ( down == NULL ) 
            {
                down = new node(s[p+1]);
                //adicionado para contar os sufixos que começam pela letra
                // ou prefixo que terminam pela letra (não podem ser vazio)
                last[(int)s[p+1]-'a']++;
                size++;
            }
            else if (down->c > s[p+1])
            {
                node *aux = down;
                down = new node(s[p+1]);
                //adicionado para contar os sufixos que começam pela letra
                // ou prefixo que terminam pela letra (não podem ser vazio)
                last[(int)s[p+1]-'a']++;
                down->right = aux;
                size++;
            }
            down->insert(p+1, max(sum, out));
        }
        else if (s[p] > c)
        {
            if ( right == NULL ) 
            {
                right = new node(s[p]);
                //adicionado para contar os sufixos que começam pela letra
                // ou prefixo que terminam pela letra (não podem ser vazio)
                if(p>0)last[(int)s[p]-'a']++;
                size++;
            }
            else if ( right->c > s[p] )
            {
                node *aux = right;
                right = new node(s[p]);
                //adicionado para contar os sufixos que começam pela letra
                // ou prefixo que terminam pela letra (não podem ser vazio)
                if(p>0)last[(int)s[p]-'a']++;
                right->right = aux;
                size++;
            }
            right->insert(p, sum);
        }
    }

    node* getPointer(char val)
    {
        if (c == ' ')
        {
            node *n = right;
            while (n != NULL)
            {
                if ( n->c == val ) return n;
                if (n->c > val) return this;
                n = n->right;
            }
            return this;
        }

        node *n = down;
        while (n != NULL)
        {
            if ( n->c == val ) return n;
            if (n->c > val) return NULL;
            n = n->right;
        }
        return NULL;
    }

    void print(int lvl=0)
    {
        for (int i = 0; i < lvl; ++i) cout << " ";
        cout << c << "(" << out << ")" << endl;
        if ( down != NULL ) down->print(lvl+1);
        if (right != NULL) right->print(lvl);
    }

    void free()
    {
        if ( down != NULL )
        {
            down->free();
            delete down;
            down = NULL;
        }
        if (right != NULL)
        {
            right->free();
            delete right;
            right = NULL;
        }
    }

    void dfs(int lvl)
    {
        if(lvl > 0) ret -= last[(int)c-'a'];
        if(down != NULL)
        {
            down->dfs(lvl+1);
        }
        if(right != NULL) 
        {
            right->dfs(lvl);
        }
    }
};

node port;
node esp;

char ch[10005];
int main()
{
    int p, e, cnt, esize, psize;
    while (scanf("%d%d", &p, &e) && p)
    {
        port.free();
        esp.free();
        size = 0;
        memset(last,0,sizeof(last));
        for(int i=0;i<p;i++)
        {
            cin >> s;
            port.insert(0);
        }
        psize = size;
        size = 0;
        memset(last,0,sizeof(last));
        for(int i=0;i<e;i++)
        {
            cin >> s;
            reverse(s.begin(),s.end());
            esp.insert(0);
        }
        esize = size;
        ret = (long long)esize*psize;
        port.dfs(0);
        cout << ret << endl;
    }
}


