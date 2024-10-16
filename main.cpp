int main()
{

    // 全アカウントを格納するコンテナ
    vector<Account> user;
    vector<Account>::iterator account_iter;

    // 入力される数字を格納する変数
    int key;

    // 新規ユーザーか否か調べる
    start:


    while (1)
    {
        cout << "ようこそ。\nすでに登録している方は１を、まだ登録していないご新規様は２を入力してください：" << endl;

        //１か２を入力させる
        

        // １か２以外が入力され続けるとループになる
        for (; !(cin >> p) || !(p == 1 || p == 2);)
        {
            cout << "１か２を入力しろよ。" << endl;
            cout << "ほれ入力->" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }

        // 新規ユーザーの場合　
        if (p == 2)
        {
            // 新参者のローカルオブジェクトを作成
            Account newbee;

            cout << "新規登録をしましょう\n";
            newbee.write_name();
            cout << endl;
            newbee.write_password();
            cout << endl;
            cout << "登録完了です。お疲れ様でした。" << endl;

            // newbeeをall_memberコンテナに格納する

            user.push_back(newbee);
        }
        else if (p == 1)
        {
            Account someone;
            Label:
            cout << "個人情報の照合を開始します。" << endl;
            cout << "以下の情報を正しく入力してください。" << endl;
            someone.write_name();
            someone.write_password();

            for (std::size_t i = 0; i != std::size(user); ++i)
            {
                if (user.at(i).get_name() == someone.get_name() && user.at(i).get_password() == someone.get_password())
                {
                    cout << "認証成功です。ログインします。" << endl;

                    int keep_login = 1;
                    while (keep_login == 1)
                    {
                        // 預金などの選択
                        int q;
                        cout << "取引を終了するなら０、預金の確認なら１を、預入またはお引き出しなら２を押してください：" << endl;
                        for (; !(cin >> q) || !(q == 1 || q == 2 || q == 0);)
                        {
                            cout << "０か1か２を入力してね" << endl;
                            cout << "ほれ:" << endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                        }

                        //0が押され、取引の終了を求められる場合
                        if (q == 0)
                        {
                            cout << "お取引を終了いたします。最初の画面に戻ります。" << endl;
                            goto start;
                        }

                        // 1が押され、預金の確認を求められる場合
                        if (q == 1)
                        {
                            cout << "預金:" << user.at(i).get_money() << "\n";
                        }

                        // 2が押されて、預入または引き出しが求められる場合
                        else
                        {
                            user.at(i).write_money();
                        }
                        for (; !(cin >> keep_login) || !(keep_login == 0 || keep_login == 1);)
                        {
                            cout << "引き続きお取引をする場合は１を、取引を終了する場合は0を入力してください。:";
                            cin.clear();
                            cin.ignore(256, '\n');
                        }
                    }
                }
                else
                {
                    cout << "認証失敗です。登録名またはパスワードを再度確認して入力し直してください。\n --------------------------------------" << endl;
                    goto Label;
                }
            }
        }
    }
}