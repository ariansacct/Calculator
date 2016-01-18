#include <iostream>
#include <string>

using namespace std;

int calculate(string exp);

int main (){
	string exp;
	while (cin >> exp)
		cout << calculate(exp) << endl;
return 0;
}

int calculate(string exp)
{
	if (exp[0] != '(')
		return atoi(exp.c_str());

	string oprnd1;
	string oprnd2;
	int i, ctr = 0;
	for (i=1; i < exp.length() - 1; i++){
		if (exp[i]=='(')
			ctr++;
		if (exp[i]==')')
			ctr--;
		if (ctr==0 && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'))
			break;
		}
	oprnd1 = exp.substr(1,i-1);
	oprnd2 = exp.substr(i+1,exp.size()-i-2);
	int result1 = calculate(oprnd1);
	int result2 = calculate(oprnd2);
	switch (exp[i])
	{
	case '+':
		return result1 + result2;
		break;
	case '-':
		return result1 - result2;
		break;
	case '*':
		return result1 * result2;
		break;
	case '/':
		return result1 / result2;
		break;
	}

}