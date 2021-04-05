#include"p.h"
#include <iostream>
#include <string> 

using namespace std;

int main(){

    float output;
    bool broken=false;

    string input_s;
   
        string* temp = new string;
        while (1)
        {
            if (broken) { break; }

            cin >> input_s;

            if (input_s.empty())
            {
                std::cout << "非法输入"; cin.clear(); cin.get(); continue;
            }

            for (int i = 0; i < input_s.length(); i++)
            {
                if (input_s[i] == 45 || input_s[i] == 47 || (input_s[i] <= 43 && input_s[i] >= 40) || (input_s[i] <= 57 && input_s[i] >= 48))
                {
                    broken = true;
                    continue;
                }
                else
                {
                    std::cout << "非法输入"; cin.clear(); cin.get(); break;
                }
            }

        }//判断非法输入

        postfix(input_s, *temp);
      
        output = Calculator(*temp);
        std::cout << "\n结果为 " << output;

   
}
