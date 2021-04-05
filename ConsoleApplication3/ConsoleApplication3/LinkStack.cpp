#include <iostream>
#include<cmath>
#include <stack> 
#include <string> 
#include"p.h"

using namespace std;

enum Operator {
	add = 0,
	subtract = 0,
    multiply=1,
    divide=1,

};

void postfix(string temp,string& output)
{
	stack<char>s1;
	char *temp_char=new char;
	for (int i = 0; i < temp.length(); i++)
	{
		if ((temp[i] <= 57 && temp[i] >= 48))
		{
			output.append(1, temp[i]);

		}
		else if (temp[i] == '(') 
		{
			s1.push(temp[i]);
		}
		else if (temp[i] == ')') 
		{
			while (1)
			{
				if(s1.empty()) return;
				if (s1.top() == '(')
				{
					*temp_char = s1.top();
					s1.pop();
					break;
				}
				*temp_char = s1.top();
				s1.pop();
				output.append(1, *temp_char);
					
			}
		}
		else if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/')
		{
			int a, b;

			if (temp[i] == '+') a = 0;
			else if (temp[i] == '-') a = 0;
			else if (temp[i] == '*') a = 1;
			else if (temp[i] == '/') a = 1;

			while (1)
			{
				if (s1.empty()) 
				{
					s1.push(temp[i]); break;
				}
				*temp_char = s1.top();
				
					if (*temp_char == '+') b = 0;
					else if (*temp_char == '-') b = 0;
					else if (*temp_char == '*') b = 1;
					else if (*temp_char == '/') b = 1;
					else if (*temp_char == '(') s1.push(temp[i]); break;
				


				if (a > b)
				{
					s1.push(temp[i]); break;
				}
				else 
				{
					s1.pop();
					output.append(1, *temp_char);
				}
			}
		}
		
	}
	while (!s1.empty())
	{
			*temp_char = s1.top();
			s1.pop();
			output.append(1, *temp_char);
	}

}

float Calculator(string input) 
{
	float output;
	float temp=0;
	float a, b;
	stack<float>s3;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] <= 57 && input[i] > 48) {
			s3.push((int)input[i] - 48);
		}
		else if (input[i] == '+') {
			a = s3.top();
			s3.pop();
			b = s3.top();
			s3.pop();
			temp = a + b;
			s3.push(temp);
		}
		else if (input[i] == '-') {
			a = s3.top();
			s3.pop();
			b = s3.top();
			s3.pop();
			temp = b - a;
			s3.push(temp);
		}
		else if (input[i] == '*') {
			a = s3.top();
			s3.pop();
			b = s3.top();
			s3.pop();
			temp = a * b;
			s3.push(temp);
		}
		else if (input[i] == '/') {
			a = s3.top();
			s3.pop();
			b = s3.top();
			s3.pop();
			temp = b / a;
			s3.push(temp);
		}
	}
	output = s3.top();
	return output;
}
