#pragma once
#include <stack>
#include <string>
using namespace std;

class Postfix
{
private:
	string postExpr;
	stack<int> opStack;
	bool isOper(char op);
	int compute(int lhs, int rhs, char op);
public:
	Postfix() : postExpr(""){}
	void set(string ex) { postExpr = ex; }
	string get() { return postExpr; }
	int evaluate();
};

int Postfix::compute(int lhs, int rhs, char op)
{
	switch (op)
	{
	case '*': return lhs * rhs;
	case '/': return lhs / rhs;
	case '+': return lhs + rhs;
	case '-': return lhs - rhs;
	}
	return 0;
}

bool Postfix::isOper(char op)
{
	return op == '*' || op == '/' || op == '+' || op == '-';
}

int Postfix::evaluate()
{
	char ch = ' ';
	int l = 0, r = 0;
	for (string::size_type i = 0; i < postExpr.size(); i++)
	{
		ch = postExpr.at(i);
		if (isdigit(ch))
			opStack.push(ch - '0');
		else if (isOper(ch))
		{
			r = opStack.top();
			opStack.pop();
			l = opStack.top();
			opStack.pop();
			opStack.push(compute(l, r, ch));
		}
	}
	return opStack.top();
}


