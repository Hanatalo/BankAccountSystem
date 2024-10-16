class Account
{
private:
    // name
    string name;
    // password
    string password;
    // money
    int money;
    // The number of the clints.
    //int member_number;

public:
    // Get account information

    string get_name();
    string get_password();
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
    Account();

    // destructer
    ~Account();
};
