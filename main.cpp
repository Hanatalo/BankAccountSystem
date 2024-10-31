#include "all.h"

// アカウントを作成して入/出金するプログラム

int main()
{

    // 全アカウントを格納するコンテナ
    std::vector<Account> user;

    // 新規ユーザーか否か調べる

    // アカウント登録、既存ユーザーへの取引を走らせ続ける

    while (true)
    {

        // 新規/既存ユーザーを分ける
        int num; // 　入力される数字

        std::cout << "アカウントをお持ちの方は１を、新規アカウントを開設する方は２を入力してください。\n";
        std::cout << "入力:";
        std::cin >> num;

        // 入力エラー処理
        while (std::cin.fail() || !(num == 1 || num == 2))
        {
            error_clear();
            std::cout << "不正な値が入力されています。 再入力してください/n" << std::endl;
            std::cout << "数字の１か２を入力:";
            std::cin >> num;
        }

        // 上記の入力に基づいて新規ユーザーと既存ユーザーの処理を行う

        // num = 1なら trueで既存ユーザー　num =2 なら falseで新規ユーザー

        if (log_in(num)) // 既存ユーザーの場合
        {
            std::string account_name; // アカウント名
            std::string password;     // パスワード

            std::cout << "アカウントネームを入力してください。\n";

            std::cout << "アカウントネームを入力:";
            std::cin >> account_name;
            std::cout << "パスワードを入力してください。\n";
            std::cout << "パスワードを入力:";
            std::cin >> password;

            // 入力ミスがあった場合
            while (std::cin.fail())
            {
                std::cout << "不正な文字が入力されています。再入力してください。\n";
                std::cout << "アカウントネームを入力：\n";
                std::cin >> account_name;
                std::cout << "パスワードを入力：\n";
                std::cin >> password;
                error_clear();
            }

            // ユーザーの照合を行う

            // userに格納されているすべてのオブジェクトの名前、パスワードと入力情報を照合する
            for (auto iter = user.begin(); iter != user.end(); iter++)
            {
                // ユーザーネームとパスワードの両方が一致した場合
                if (iter->get_name() == account_name && iter->get_password() == password)
                {
                    std::cout << "確認が取れました。ログインします。" << std::endl;
                    // 入出金を行う
                    bool keep_dealing = true;
                    // 入力を受け取る
                    while (keep_dealing)
                    {
                        int key; // 以下の数字を入力させるための一時的な変数
                        // 取引を行う

                        std::cout << "預金額を表示する場合は０、入金出金または借入する方は1を、取引をやめて最初の画面に戻る場合は2を入力してください>\n";

                        do // 0、１、２のどれかが入力されるまで繰り返す。
                        {
                            std::cout << "入力:";
                            std::cin >> key;
                            if (std::cin.fail())
                            {
                                std::cout << "不正な値が入力されました。再入力してください。\n";
                            }
                        } while (std::cin.fail() || !(key == 0 || key == 1 || key == 2));

                        if (key == 0)
                        {
                            std::cout << "残金:" << iter->get_money() << "\n";
                        }
                        else if (key == 1)
                        {
                            iter->write_money();
                        }
                        else
                        {
                            std::cout << "ご利用ありがとうございました\n";
                            keep_dealing = false;
                        }
                    }
                }
                else // 照合した結果、既存ユーザーに存在しなかった
                {
                    std::cout << "確認が取れませんでした。やり直してください。" << std::endl;
                }
            }
        }
        else // num = 2でlog_inがfalseの場合、新規アカウントを作成する
        {
            std::string new_account_name; // 新しいアカウント名
            std::string new_password, check_password;
            // 新しいパスワードと確認用パスワード
            std::cout << "これからアカウントの開設を行います。以下の項目を入力してください。\n";
            do
            {
                std::cout << "アカウント名を入力:";
                std::cin >> new_account_name;
                std::cout << "\n";
                std::cout << "パスワードを入力:";
                std::cout << "\n";
                std::cin >> new_password;
                std::cout << "パスワードをさ入力:";
                std::cin >> check_password;
                if (std::cin.fail())
                {
                    std::cout << "不正な値が入力されています。再入力してください。\n";
                }
            } while (std::cin.fail() || !(new_password == check_password));

            std::cout << "new_account_name様のアカウントは作成されました。\n";

            // ユーザー情報を格納する
            user.push_back(Account(new_account_name, new_password, 0));
        }
    }
    return 0;
}