
#include <string>

// Accountの宣言
class Account
{
private:
    // name
    std::string name;
    // password
    std::string password;
    // money
    int money;
    // オブジェクト数
    static int objNum;
    // ユーザー番号
    int number;

public:
    // ログイン時の質問
    bool log_in(int num);
    // Get account information

    std::string get_name();
    std::string get_password();
    int get_money();

    // input functoins

    // input the name
    void write_name();
    // input the password
    void write_password();
    // input the money
    void write_money();

    // output functions

    // output name
    void read_name();
    // output password
    void read_password();
    // output money
    void read_money();

    // constructer
    Account();                                                  // 引数なしのコンストラクター
    Account(std::string name, std::string password, int money); // 引き数ありのコンストラクター

    // destructer
    ~Account();
};
