#include <iostream>
#include"SqStack.h"


int main()
{
	SqStack *s=new SqStack;
	int sizes;
	int temp;
	int* output = new int;
	int input;
	bool broken;
	while (1)
	{
		broken = false;
		std::cout << "创建一个栈，输入存储长度\n";
		while (1)
		{
			std::cin >> sizes;
			if (!std::cin)
			{
				std::cin.clear();
				std::cin.get();
				std::cout << "非法输入\n";
			}
			else
				break;
		}//输入异常处理
		initStack(s, sizes);
		while (1)
		{
			std::cout << "1.判断栈是否为空\n2.得到栈顶元素\n3.清空栈\n4.销毁栈\n5.检测栈长度\n6.入栈\n7.出栈\n";
			while (1)
			{
				std::cin >> temp;
				if (!std::cin)
				{
					std::cin.clear();
					std::cin.get();
					std::cout << "非法输入\n";
				}
				else
					break;
			}//输入异常处理
			switch (temp)
			{
			case 1:isEmptyStack(s); break;
			case 2:if (getTopStack(s, output) == SUCCESS) { std::cout << "\n栈顶元素为 " << *output << "\n"; break; }
				  else break;
			case 3:clearStack(s); break;
			case 4:destroyStack(s); broken = true; break;
			case 5:stackLength(s, output); std::cout << "\n长度为 " << *output << "\n"; break;
			case 6:std::cout << "请输入入栈的元素\n"; std::cin >> input; pushStack(s, input); break;
			case 7:if (popStack(s, output) == SUCCESS) { std::cout << "\n出栈元素为 " << *output << "\n"; break; }
				  else break;
			default:std::cout << "\n请输入正确的数字\n";
			}
			if (broken) break;
		}
	}
}
