        int res = str[i].find("g");
        // str[i].replace(res, 1, "$");
        // res = str[i].find("s");
        // cout<<str[i]<<endl;
        while (res != -1)
        {
        str[i].replace(res, 1, "$");
        res = str[i].find("g");
        }
        cout << str[i] << endl;