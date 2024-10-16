//メンバー関数の定義

void Account::write_name()
{
    cout << "ユーザーネームを入力しよう！\n"
         << "名前:";
    cin >> this->name;
}
void Account::write_money()
{
    int money;
    cout << "預入、またはお引き出し金額を入力してください。" << "金額:";
    cin >> money;
    this->money = this->money + money;
}
void Account::write_password()
{
    cout << "パスワードを入力しよう！\n";
    cout << "パスワード:";
    cin >> this->password;
}

void Account::read_name()
{
    cout << this->name << "\n";
}
void Account::read_money()
{
    cout << this->money << "\n";
}
void Account::read_password()
{
    cout << this->password << "\n";
}

string Account::get_name()
{
    return this->name;
}
string Account::get_password()
{
    return this->password;
}
int Account::get_money()
{
    return this->money;
}

Account::Account()
{
    this->name = "unasigned";
    this->money = 0;
    this->password = "password";
    //member_number++;
}

Account::~Account() {}
