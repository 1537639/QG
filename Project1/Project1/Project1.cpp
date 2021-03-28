// Project1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "qg.h"



int main()
{
    int temp;
    int input,input_2;
    QGForwardList qg;

    while (1) {
        std::cout << "链表： ";
    
        std::cout << "\n\n1.返回链表中第一个元素的引用\n2.返回链表中最后一个元素的引用\n3.在链表第一个元素前添加元素e\n4.删除链表第一个元素\n5.在链表最后一个元素后添加元素e\n6.删除链表最后一个元素\n7.在链表的第index + 1个元素前插入元素e\n8.删除任意位置元素\n9.清空链表\n10.查找元素是否存在\n11.返回链表中元素的数量\n12.遍历链表, 对每个元素调用visit指向的函数\n13.反转链表\n14.链表判环\n15.偶节点反转\n16.返回中间节点\n\n输入对应数字\n";

        

        std::cin >> temp;

        switch (temp) {
        case 1:std::cout << "\n\n" << qg.front()<<"\n\n"; break;
        case 2:std::cout << "\n\n" << qg.back() << "\n\n"; break;
        case 3:std::cout << "\n输入值为"; std::cin >> input; qg.push_front(input); break;
        case 4:qg.pop_front(); break;
        case 5:std::cout << "\n输入值为"; std::cin >> input; qg.push_back(input); break;
        case 6:qg.pop_back(); break;
        case 7:std::cout << "\n输入值为"; std::cin >> input >> input_2; qg.insert(input, input_2); break;
        case 8:std::cout << "\n输入值为"; std::cin >> input; if (qg.erase(input)) std::cout << "删除成功"; else std::cout << "删除失败"; break;
        case 9:qg.clear(); break;
        case 10:std::cout << "\n输入值为"; std::cin >> input; if (qg.contain(input))std::cout << "\n存在\n"; else std::cout << "\n不存在\n";  break;
        case 11:std::cout << "\n\n" << qg.size() << "\n\n"; break;
        case 12:; break;
        case 13:qg.reverse(); break;
        case 14:if (qg.isLoop()) std::cout << "成环\n"; else std::cout << "不成环\n"; break;
        case 15:qg.reverseEven(); break;
        case 16:std::cout << "\n\n" << qg.middleElem() << "\n\n"; break;
        default:std::cout << "输入错误\n";
        }
    }
   return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
