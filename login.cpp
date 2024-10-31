#include <iostream>
#include "login.hpp"
bool log_in(int num)
{
    // 1なら既存ユーザー
    if (num == 1)
    {
        return true;
    }
    else if // 　２なら新規ユーザー
        (num == 2)
    {
        return false;
    }
    else
    {
        std::cout << "不正な値が入力されています。\n";
        return 0;
    }
}