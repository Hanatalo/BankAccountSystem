#include "all.h"

int main()
{

    std::cout << "updatedfoo　second" << std::endl;
    // 全アカウントを格納するコンテナ
    std::vector<Account> user;
    std::vector<Account>::iterator account_iter;

    // 新規ユーザーか否か調べる

    // アカウント登録、既存ユーザーへの取引を走らせ続ける

    while (true)
    {

        int num;

        // ユーザーに１か２を入力させる

        while (true)
        {
            std::cout << "フォオオおおここに戻ってくるで間違いない？" << std::endl;
            std::cout << "アカウントをお持ちの方は１を、新規アカウントを開設する方は２を入力してください。:" << std::endl;
            std::cin >> num;
            // 入力エラー処理
            if (std::cin.fail())
            {
                error_clear();
                std::cout << "もう一度入力し直してください" << std::endl;
            }
            else

            {
                break; // 正しく入力できたらループを抜ける
            }
        }

        // 上記の入力に基づいて新規ユーザーと既存ユーザーの処理を行う
        switch (num)
        {
            {
            case 1:
                // 既存ユーザーの場合

                std::string account_name; // アカウント名
                std::string password;     // パスワード
                // アカウント名とパスワードを入力させる
                std::string key = "closed";
                while (key == "closed")
                {

                    std::cout << "アカウント名を入力してください:" << std::endl;
                    std::cin >> account_name;
                    std::cout << "パスワードを入力してください:" << std::endl;
                    std::cin >> password;

                    // 入力エラー処理
                    if (std::cin.fail())
                    {
                        error_clear();
                        std::cout << "変な文字で入力してない？半角ローマ字入力でもう一度入力し直して！再チャレンジ！" << std::endl;
                    }
                    else // 正しくパスワードが入力された場合は照合を行う
                    {
                        // userに格納されているすべてのオブジェクトの名前、パスワードと入力情報を照合する
                        for (auto iter = user.begin(); iter != user.end(); iter++)
                        {
                            // ユーザーネームとパスワードの両方が一致した場合はループを抜ける
                            if (iter->get_name() == account_name && iter->get_password() == password)
                            {
                                std::cout << "確認が取れたz。ログインします。" << std::endl;
                                key = "opened"; // 次に進む
                                break;
                            }
                            else // 照合した結果、既存ユーザーに存在しなかった
                            {
                                std::cout << "確認が取れませんでした。やり直してください。え？だれ？" << std::endl;
                            }
                        }
                    }
                }
            }
            break; // case１から出る

        case 2: // 新規アカウントを作成する

        {
            std::string new_account_name; // 新しいアカウント名
            std::string new_password, check_password;
            // 新しいパスワードと確認用パスワード
            std::cout << "これからアカウントの開設を行います。以下の項目を入力してください。" << std::endl;

            // アカウント名を正しく入力させる
            while (true)
            {
                std::cout << "アカウント名:" << std::endl;
                std::cin >> new_account_name; // 新しく作るアカウント名を入力させる

                // 正しく入力できるまでループ
                if (std::cin.fail())
                {
                    error_clear();
                    std::cout << "入力に誤りがあります。ボケェ\nもう一度ローマ字入力してみて！" << std::endl;
                }
                else
                {
                    break; // 入力が正しくできたらループを抜ける
                }
            }

            std::cout << "次はパスワードの設定をしましょう。" << std::endl;

            // パスワードを正しく入力させる
            while (true)
            {
                std::cout << "パスワード" << std::endl;
                std::cin >> new_password;
                std::cout << "パスワードを再入力:" << std::endl;
                std::cin >> check_password;

                // 入力ミスがあった場合はループの先頭に戻る
                if (std::cin.fail() || new_password != check_password)
                {
                    error_clear();
                    std::cout << "入力に誤りがあります。ボケェ\nもう一度ローマ字入力してみて！" << std::endl;
                }
                else
                {
                    break; // 入力ミスがなかったらループから抜ける
                }
            }
            std::cout << new_account_name << "様、アカウント開設ありがとうございます。" << std::endl;
            // 新規ユーザーのアカウントを作成、データをuserに格納する
            user.push_back(Account(new_account_name, new_password, 0));
        }
        break;

        default:
            break;
        }

        // 入出金を行う

        // 入力を受け取る
        while (true)
        {
            std::cout << "預金額を表示する場合は０、入金出金または借入する方は1を、取引をやめて最初の画面に戻る場合は2を入力して->" << std::endl;
            std::cin >> num;

            if (!(std::cin.fail()) && (num == 0) || (num == 1) || (num == 2) || (num == 3))
            {
                break; // ただし入力の場合は次のステップに進む
            }
            else
            {
                std::cout << "は？もう一回聞くよ？" << std::endl;
            }
        }

        // 取引をする
        while (num != 2)
        {
            switch (num)
            {
            case 0:
                std::cout << user.at(0).get_name() << "様の貯金額は、" << user.at(0).get_money() << "円みたいだぞ" << std::endl;
                std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;
                std::cout << "次のお取引に移りまーす" << std::endl;
                std::cout << "預金額を表示する場合は０、入金出金または借入する方は1を、取引をやめて最初の画面に戻る場合は2を入力して->" << std::endl;
                std::cin >> num;
                break;
            case 1:
            {
                user.at(0).write_money();
                std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;
                std::cout << "次のお取引に移りまーす" << std::endl;
                std::cout << "預金額を表示する場合は０、入金出金または借入する方は1を、取引をやめて最初の画面に戻る場合は2を入力して->" << std::endl;
                std::cin >> num;
                break;
            }
            default:
                break;
            }
        }

        std::cout << "ご利用ありがとうございやしたー" << std::endl;
    }
}
