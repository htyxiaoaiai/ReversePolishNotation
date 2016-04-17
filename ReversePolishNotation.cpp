# ReversePolishNotation
逆波兰表达式的求解

#include"ReversePolishNotation.h"
using namespace std;

int CountPRN(const Cell* a,size_t size)
{
	assert(a);//断言
	stack<int> s;
	for (unsigned int i = 0; i < size; i++)
	{
		if (a[i]._type == OP_NUM)
		{
			s.push(a[i]._value);
		}
		else
		{
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			switch (a[i]._value)
			{
			case ADD:
			{
				s.push(left + right);
				break;
			}
			case SUB:
			{
				s.push(left - right);
				break;
			}
			case MUL:
			{
				s.push(left * right);
				break;
			}
			case DIV:
			{
				if (right == 0)
				{
					throw exception("除数不能为0");
				}
				s.push(left / right);
				break;
			}
			default:
				break;
			}
		}
	}
	return s.top();
}
void Test()
{
	Cell array[] =
	{
		{ OP_NUM,12},
		{ OP_NUM,3 },
		{ OP_NUM,4 },
		{ OP_SYMBOL,ADD},
		{ OP_SYMBOL,MUL},
		{ OP_NUM,6 },
		{ OP_SYMBOL,SUB},
		{ OP_NUM,8 },
		{ OP_NUM,2 },
		{ OP_SYMBOL,DIV},
		{ OP_SYMBOL,ADD},
	};
	try
	{
		cout << CountPRN(array, sizeof(array) / sizeof(array[0])) << endl;
	}
	catch (exception e)
	{
		cout << "除数不能为0" << endl;
	}
}
	

int main()
{
	Test();
	getchar();
	return 0;
}
