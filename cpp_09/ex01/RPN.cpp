#include"RPN.hpp"


RPN::RPN(/* args */)
{
}

RPN:: RPN(const RPN & src)
{
	*this = src;
}

RPN & RPN:: operator=(const RPN & rhs)
{
	if(this != &rhs)
		*this = rhs;
	return *this;
}

RPN::~RPN()
{
}
int	RPN::checkOperand(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	else
		return -1;	
}

int	RPN::checkOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return 1;//char is an operator
	else
		return -1;// char is not oprator || its an operand
	
}

int	RPN::checkSpace(char ch)
{
	if (isspace(ch))
		return 1;
	else
		return -1;
}

int	RPN::charToInt(char ch)
{

	int	value;
	value = ch;
	int finalValue = value - '0';
	return finalValue;

}

int	RPN::operation(int a, int b, char ch)
{
	if (ch == '+')
		return b + a;
	else if (ch == '-')
		return b - a;
	else if (ch == '*')
		return b * a;
	else if (ch == '/')
	{
		if (a != 0)
		{
            return b / a;
        } else
		{
            std::cerr << "Error: Division by zero." << std::endl;
            throw std::runtime_error("Invalid input");
        }
    }
	else
	{
        std::cerr << "Error: Unknown operator." << std::endl;
        throw std::runtime_error("Invalid input");
    }
	// return 0;
}


int	RPN::performPostfix(std::string post)
{
	std::cout<<"post =av[1]: "<<post<<std::endl;
	int	a;
	int	b;
	std::stack<int> stk;
	std::string::const_iterator	it;
	for (it = post.begin(); it != post.end(); it++)
	{
		if (checkOperator(*it) != -1)
		{
			if (stk.size() < 2 && it + 1 != post.end()) {
				std::cerr << "Error: Insufficient operands for operation." << std::endl;
				throw std::runtime_error("Invalid input");
			}
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
		else {
            std::cerr << "Error: Invalid character in input - '" << *it << "'" << std::endl;
            throw std::runtime_error("Invalid input");
        }
	}
	
	  if (stk.size() != 1) {
        std::cerr << "Error: Insufficient operands for operation." << std::endl;
        throw std::runtime_error("Invalid input");
    }
	return stk.top();
	
}

// int	main()
// {
// 	std::string	postfix	=  "4 2 + +";
// 3 4 + 5 * 2 - = 33;
// 	int	result	= performPostfix(postfix);
// 	std::cout<<"result: "<<result<<std::endl;
// 	return 0;
// }