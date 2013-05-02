#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int n;
    string p[] = {" ","Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson","Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield","Arthur","Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan","Bush","Clinton"};
    scanf("%d", &n);
    cout << p[n] << endl;
    return 0;
}
