
// ユーザーが新規ユーザーか既存ユーザーか判定するだけの機能
#include "oneORtwo.hpp"
#include <iostream>
bool oneORtwo(int value)
{
    if (value == 1 || value == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
