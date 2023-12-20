#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include<iostream>
#include <sstream>
#include<cmath>
class RPN
{
	private:
		RPN(const RPN & src);
		RPN & operator=(const RPN & rhs);

	public:
		RPN();
		~RPN();
		int	checkOperator(char ch);
		int	checkOperand(char ch);
		int	checkSpace(char ch);
		int	charToInt(char ch);
		int	operation(int a, int b, char ch);
		int	performPostfix(std::string post);

};



#endif
