#include <iostream>
#include <limits>
#include "error_clear.hpp"

// エラー状態を解決する
void error_clear()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n'); // バッファをクリアにする
}
