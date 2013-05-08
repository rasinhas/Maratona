#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	int n;
	int i, j, aux, len;
	char eq[40];
	vector <char> ops1, ops2;
	vector <long long int> num1, num2;
	scanf("%d", &n);
	for(j=0;j<n;j++)
	{
		scanf("%s", eq);
		len = strlen(eq);
		for(i=0;i<len;i++)
		{
			if(eq[i] == '+' || eq[i] == '*')
			{
				ops1.push_back(eq[i]);
				ops2.push_back(eq[i]);
				aux = (int)(eq[i-1]-48);
				if(eq[i-2] != '+' && eq[i-2] != '*' && i-2 >= 0)
					aux += 10*(eq[i-2]-48);
				num1.push_back(aux);
				num2.push_back(aux);
			}
		}
		aux = (int)(eq[len-1]-48);
		if(eq[len-2] != '+' && eq[len-2] != '*')
			aux += 10*(eq[len-2]-48);
		num1.push_back(aux);
		num2.push_back(aux);
		for(i=0;i<ops1.size();i++)
		{
			if(ops1.at(i) == '*')
			{
				num1.at(i) = num1.at(i) * num1.at(i+1);
				num1.erase(num1.begin()+i+1);
				ops1.erase(ops1.begin()+i);
				i--;
			}
		}
		for(i=0;i<ops1.size();i++)
		{
			if(ops1.at(i) == '+')
			{
				num1.at(i) = num1.at(i) + num1.at(i+1);
				num1.erase(num1.begin()+i+1);
				ops1.erase(ops1.begin()+i);
				i--;
			}
		}
		for(i=0;i<ops2.size();i++)
		{
			if(ops2.at(i) == '+')
			{
				num2.at(i) = num2.at(i) + num2.at(i+1);
				num2.erase(num2.begin()+i+1);
				ops2.erase(ops2.begin()+i);
				i--;
			}
		}
		for(i=0;i<ops2.size();i++)
		{
			if(ops2.at(i) == '*')
			{
				num2.at(i) = num2.at(i) * num2.at(i+1);
				num2.erase(num2.begin()+i+1);
				ops2.erase(ops2.begin()+i);
				i--;
			}
		}
		printf("The maximum and minimum are %lld and %lld.\n", num2.front(), num1.front());
		ops1.clear();
		ops2.clear();
		num1.clear();
		num2.clear();
	}
	return 0;
}


