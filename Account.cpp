#include "Account.hpp"
#include <iostream>
#include <string>

// メンバー関数の定義

void Account::write_name()
{
    std::cout << "ユーザーネームを入力しよう！\n"
              << "名前:";
    std::cin >> this->name;
}
void Account::write_money()
{
    int money;
    std::cout << "預入、またはお引き出し金額を入力してください。" << "金額:";
    std::cin >> money;
    this->money = this->money + money;
}
void Account::write_password()
{
    std::cout << "パスワードを入力しよう！\n";
    std::cout << "パスワード:";
    std::cin >> this->password;
}

void Account::read_name()
{
    std::cout << this->name << "\n";
}
void Account::read_money()
{
    std::cout << this->money << "\n";
}
void Account::read_password()
{
    std::cout << this->password << "\n";
}

std::string Account::get_name()
{
    return this->name;
}
std::string Account::get_password()
{
    return this->password;
}
int Account::get_money()
{
    return this->money;
}

Account::Account()
{
    money = 0;
}
Account::Account(std::string name, std::string password, int money) : name(name), password(password), money(0)
{
}

Account::~Account() {}
