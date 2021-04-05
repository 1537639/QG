

#include <iostream>
#include"LinkStack.h"

int main()
{
	LinkStack* s = new LinkStack;
	int sizes;
	int temp;
	int* output = new int;
	int input;
	bool broken;
	while (1)
	{
		broken = false;
		std::cout << "创建了一个新的栈\n";
		
		initLStack(s);
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
			case 1:isEmptyLStack(s); break;
			case 2:if (getTopLStack(s, output) == SUCCESS) { std::cout << "\n栈顶元素为 " << *output << "\n"; break; }
				  else break;
			case 3:clearLStack(s); break;
			case 4:destroyLStack(s); broken = true; break;
			case 5:LStackLength(s, output); std::cout << "\n长度为 " << *output << "\n"; break;
			case 6:std::cout << "请输入入栈的元素\n"; std::cin >> input; pushLStack(s, input); break;
			case 7:if (popLStack(s, output) == SUCCESS) { std::cout << "\n出栈元素为 " << *output << "\n"; break; }
				  else break;
			default:std::cout << "\n请输入正确的数字\n";
			}
			if (broken) break;
		}
	}
}
