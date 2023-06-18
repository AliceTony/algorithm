class Solution {
private:
    bool check_int(int &now , string &s){
        if (s[now] == '+' || s[now] == '-')now++;
        bool ok = 0;
        while(isdigit(s[now]))now++ , ok = 1;
        return ok;
    }
    bool check_double(int &now , string &s){
        if (s[now] == '+' || s[now] == '-')now++;
        bool ok = 0;
        while(isdigit(s[now]))now++ , ok = 1;
        if (s[now] == '.') now++;
        else return 0;
        while(isdigit(s[now]))now++ , ok = 1;
        return ok;
    }
public:
    bool isNumber(string s) {
        int now = 0;
        s += '/';
        for (;;now++) if (s[now] != ' ') break;
        int temp = now;
        if (check_double(temp , s)) now = temp;
        else if (!check_int(now , s)) return 0;
        if (s[now] == 'e' || s[now] == 'E'){
            now++;
            if (!check_int(now , s)) return 0;
        }
        while(s[now] != '/'){
            if (s[now] == ' ')now++;
            else return 0;
        }
        return 1;
    }
};