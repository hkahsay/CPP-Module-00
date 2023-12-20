#include"RPN.hpp"

// int main (int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		/* code */
// 	}
// 	else
// 		std::cerr<<"Error: invalid number of arguments."<<std::endl;
		
	
// }
int	checkOperand(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	else
		return -1;
	
}

int	checkOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return 1;//char is an operator
	else
		return -1;// char is not oprator || its an operand
	
}

int	checkSpace(char ch)
{
	if (isspace(ch))
		return 1;
	else
		return -1;
}

int	charToInt(char ch)
{

	int	value;
	value = ch;
	int finalValue = value - '0';
	std::cout<<"finalvalue: "<<finalValue<<std::endl;
	return finalValue;

}

int	operation(int a, int b, char ch)
{
	if (ch == '+')
		return b + a;
	else if (ch == '-')
		return b - a;
	else if (ch == '*')
		return b * a;
	else if (ch == '/')
		return b / a;
	else 
		std::cerr<<"Error: operator."<<std::endl;
	return 0;
}

int	performPostfix(std::string post)
{
	int	a;
	int	b;
	std::stack<int> stk;
	std::string::iterator	it;
	for (it = post.begin(); it != post.end(); it++)
	{
		if (checkOperator(*it) != -1)
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(operation(a, b, *it));
		}
		else if(checkOperand(*it) == 1)
		{
			stk.push(charToInt(*it));
		}
		else if(checkSpace(*it) == 1)
			continue;
		else
			std::cerr<<"Error: invalid input."<<std::endl;
	}

	return stk.top();
	
}

int	main()
{
	std::string	postfix	= " 8 9 * 9 - 9 - 9 - 4 - 1 +";
	int	result	= performPostfix(postfix);
	std::cout<<"result: "<<result<<std::endl;
	return 0;
}