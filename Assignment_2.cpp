//Header files
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
//class naed stack
class Stack
{
public:
	//data menmbers
	int top;
	int size;
	int* current;
	//default constructor
	Stack()
	{
		top = -1;
		size = 5;
		current = new int[size];
	}
	bool isEmpty() {//Same function from static list
		return top == -1;
	}
	bool isFull()
	{
		if (top == size)
		{
			//expansion();
		}
		return top == size;
	}
	void expansion()//Function to dynamically expand the list
	{
		size = size * 2;
		int* narr = new int[size];
		for (int i = 0; i < top; i++)
		{
			narr[i] = current[i];
		}
		delete[] current;
		current = narr;
		cout << "Expansion complete" << endl;

	}
	void shrinking()//Function to dynamically shrink list
	{
		size = size / 2;
		int* narr = new int[size];
		for (int i = 0; i < top; i++)
		{
			narr[i] = current[i];
		}
		delete[] current;
		current = narr;
	}
	int pop()
	{
		if (!isEmpty())
		{
			int temp;
			temp = current[top];
			top--;
			// if (top <= size / 2)
			// 	shrinking();
			return temp;
		}
		else
			cout << "Array is empty" << endl;
		return -10;
	}
	//function to print data at the peak
	void Peak()
	{
		if (!isEmpty())
		{
			cout << "Data at top of stack " << current[top] << endl;
		}
		else
			cout << "Array is empty" << endl;
	}
	void clear()
	{
		if (!isEmpty())
			top = -1;
		else
			cout << "Stack already empty" << endl;
	}
	//function to put data into the stack
	void Push(int inp)
	{

		if (!isFull())
		{
			current[++top] = inp;

		}
		else
		{
			current[++top] = inp;
		}
	}
	int peak_ret()
	{
		return current[top];
	}
	//function to check the precedence
	int precedence(char ch) {
		if (ch == '^')
			return 3;
		else if (ch == '/' || ch == '*')
			return 2;
		else if (ch == '+' || ch == '-')
			return 1;
		else
			return -1;
	}

};

//main function
int  main()
{
	//declaring obejcts
	Stack stack;
	Stack stack1;
	int i = 0;
	string s;
	string postfix;
	char st;
	int val;
	char temp;
	bool validity = true;
	cout << "Enter the input" << endl;
	getline(cin, s);
	while (s[i] != '\0')
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			val = (int)s[i];
			stack.Push(val);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{

			if (stack.isEmpty())
			{
				validity = false;
			}
			st = (char)stack.pop();
			if (s[i] == ')' && st == '(')
				validity = true;
			else if (s[i] == '}' && st == '{')
			{
				validity = true;

			}
			else if (s[i] == ']' && st == '[')
				validity = true;
		}
		i++;
	}
	stack.clear();
	if (validity == true)
	{
		cout << "Is valid" << endl;
		string postfix;
		int j = 0;
		do
		{
			st = s[j];
			if (st >= '0' && st <= '9')
			{
				postfix += st;
			}
			else if (st == '(' || st == '[' || st == '{')
			{
				postfix += ' ';
				stack.Push((int)st);
			}
			else if (st == ')' || st == '[' || st == '{')
			{
				postfix += ' ';
				while (true)
				{
					postfix += (char)stack.peak_ret();
					stack.pop();
					if ((char)stack.peak_ret() == '(')
					{
						stack.pop();
						break;
					}
					stack.pop();
				}
			}

			else if (stack.isEmpty() || stack.precedence(st) > stack.precedence((char)stack.peak_ret()))
			{
				postfix += ' ';

				stack.Push((int)st);
			}
			else if (stack.precedence(st) <= stack.precedence((char)stack.peak_ret()))
			{
				while (!stack.isEmpty())
					postfix += (char)stack.pop();
				stack.Push((int)st);

			}
			else {
				postfix += ' ';
				while (!stack.isEmpty())
				{
					postfix += (char)stack.peak_ret();
					stack.pop();

				}
			}

			j++;



		} while (j != s.length() + 1);

		cout << postfix << endl;

		// Scan all characters one by one
		for (i = 0; postfix[i]; ++i)
		{
			// If the scanned character is an operand (number here),
			// push it to the stack.


			if (postfix[i] == ' ')// if the character is an empty space,
			//continue
				continue;

			else if (postfix[i] >= '0' && postfix[i] <= '9')
			{
				int num = 0;

				//extract full number
				while (postfix[i] >= '0' && postfix[i] <= '9')
				{
					num = num * 10 + (int)(postfix[i] - '0');
					i++;
				}
				i--;

				//push the element in the stack
				stack1.Push(num);
			}
			// If the scanned character is an operator, pop two
			// elements from stack apply the operator
			else
			{
				int val1 = stack1.pop();
				int val2 = stack1.pop();
				switch (postfix[i])
				{
				case '+':
					stack1.Push(val2 + val1);
					break;
				case '-':
					stack1.Push(val2 - val1);
					break;
				case '*':
					stack1.Push(val2 * val1);
					break;
				case '/':
					stack1.Push(val2 / val1);
					break;
				case '^':
					stack1.Push(pow(val2, val1));
					break;
				}
			}
		}
		cout << stack1.pop() << endl;

	}
}