#include "arithmetic.h"

Arithmetic::Arithmetic()
{
	result = 0.0;
}
Arithmetic::Arithmetic(string infix)
{
	InfixExpression = infix;
}
void Arithmetic::SetInfixExpression(void)
{
	cin >> InfixExpression;
}
void Arithmetic::ConvertExpression(void)
{
	string* ptrs = new string;
	*ptrs = InfixExpression;
	string InfixExp = *ptrs;

	string Post_temp;

	string::iterator itr_ind = InfixExp.begin();	//iterator used in index

	vector<char> stack;	//using vector as a stack!

	for (; itr_ind != InfixExp.end(); ++itr_ind)
	{
		//if stream value is not an operator -- pass
		if (operators.find(*itr_ind) == string::npos)
		{
			Post_temp += *itr_ind;
			continue;
		}

		//operator processing
		Post_temp += " ";
		switch (*itr_ind)
		{
		case'(':
			stack.push_back('(');
			break;
		case')':	//starting parenthetical calculation
			while (stack.back() != '(')
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.pop_back();
			break;
		case'+':
		case'-':	//starting add/subtract calculation
			while (stack.size() != 0 && stack.back() != '(')
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_ind);
			break;
		case'*':
		case'/':	//starting multiply/divide calculation
			while (stack.size() != 0 && (stack.back() == '*' || stack.back() == '/'))
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_ind);
			break;
		case' ':
			break;
		default:
			//unknown error
			cout << "예상치 못한 에러가 발생했습니다. 프로그램을 종료합니다." << endl;
		}
		Post_temp += " ";
	}

	size_t stacksize = stack.size();
	for (size_t i = 0; i < stacksize; ++i)
	{
		Post_temp += " ";
		Post_temp += stack.back();
		stack.pop_back();
	}

	*ptrs = Post_temp;
	PostfixExpression = *ptrs;
	delete ptrs;
	/*
	string::iterator itr_in = InfixExpression.begin();
	string::iterator itr_po = PostfixExpression.begin();
	for (; itr_in != InfixExpression.end(); itr_in++)
	{
		//when input value is not an operator
		if (operators.find(*itr_in) == string::npos)
		{
			stack_value.push(*itr_in);
			stack_value.push(' ');	//to distinguish between values, insert whitespace
		}

		//when input value is an operator
		if (*itr_in == '(')
		{
			while (*itr_in == ')')
			{
				stack_operator.push(*itr_in);
				stack_operator.push(' ');		//to distinguish between operators, insert whitespace
			}
		}
		else
		{
			if (stack_operator.empty())
			{
				stack_operator.push(*itr_in);
				stack_operator.push(' ');
			}
			else
			{
				while (!stack_operator.empty() && OperatorPriority(stack_operator.top()) >= OperatorPriority(stack_temp.back()))
				{
					stack_temp.push(*itr_in);
					stack_temp.push(' ');
				}
			}
		}

		while (!stack_operator.empty())
		{
			stack_temp.push(*itr_in);
			stack_temp.push(' ');
			stack_operator.pop();
		}
	}

	for (size_t i = 0; i < stack_temp.size(); i++)
	{
		PostfixExpression[i] = stack_temp.front();
		stack_temp.pop();
	}
	*/
}
void Arithmetic::Calculate(void)
{
	string* ptrs = new string;
	*ptrs = PostfixExpression;
	string PostfixExp;
	PostfixExp = *ptrs;

	vector<double> stack;
	string str = "";
	stringstream temp(PostfixExp);

	while (!temp.eof())
	{
		temp >> str;

		if (operators.find(str) == string::npos)
		{
			double dtemp;
			stringstream(str) >> dtemp;
			stack.push_back(dtemp);
		}
		else
		{
			double d1, d2;
			d2 = stack.back();
			stack.pop_back();
			d1 = stack.back();
			stack.pop_back();

			switch (operators[operators.find(str)])
			{
			case '+':
				stack.push_back(d1 + d2);
				break;
			case '-':
				stack.push_back(d1 - d2);
				break;
			case '*':
				stack.push_back(d1 * d2);
				break;
			case '/':
				stack.push_back(d1 / d2);
				break;
			}
		}
	}
	result = stack.back();
}
/*int Arithmetic::OperatorPriority(char _operator)
{
	if (_operator == ')')
		return 4;
	else if (_operator == '*' || _operator == '/')
		return 3;
	else if (_operator == '+' || _operator == '-')
		return 2;
	else //operator (
		return 1;
}*/