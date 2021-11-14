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