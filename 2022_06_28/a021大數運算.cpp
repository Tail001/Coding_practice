//http://maplewing.blogspot.com/2011/07/zerojudgea021.html
//https://iter01.com/593290.html
//3ms, 340KB
#include<iostream>
#include<string>
using namespace std;
class Bignum{
public:   
    int num[100];
    int digit;
    int negative = 0;

    Bignum(){
        digit = 1;
        for(int i = 0;i < 100; i++){
            num[i] = 0;
        }
        negative = 0;
    }
    Bignum(string s){
        digit = s.length();
        for(int i = 0; i < s.length(); i++){
            num[i] = s[s.length()-1-i] - '0';
        }
        for(int i = s.length(); i < 100 ;i++){
            num[i] = 0;
        }
        negative = 0;
    }
    Bignum operator + (Bignum x){
        Bignum ans;
        int max_digit = max(digit, x.digit);
        for(int i = 0;i < max_digit; i++){
            ans.num[i] += num[i] + x.num[i];
            ans.num[i + 1] = ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = max_digit + 1;
        while(!ans.num[ans.digit] && ans.digit >= 0){
            ans.digit--;
        }
        if(ans.digit <= 0)
            ans.digit = 1;
        else
            ans.digit++;

        return ans;
    }   

    Bignum operator - (Bignum x){
        Bignum ans;
        int max_digit = max(digit, x.digit);
        if(*this >= x){ // bigger minus smaller
            for(int i = 0;i < max_digit;i++){
                ans.num[i] = num[i] - x.num[i];
            }
        }
        else{ // smaller minus bigger 
            for(int i = 0;i < max_digit;i++){
                ans.num[i] = x.num[i] - num[i];
            }
            ans.negative = 1;
        }
        for(int i = 0;i < max_digit;i++){
            if(ans.num[i] < 0){
                ans.num[i+1]--; // may have problem if ans.num[++i]
                ans.num[i] += 10;
            }
        }
        ans.digit = max_digit;
        while(!ans.num[ans.digit] && ans.digit >= 0)
            ans.digit--;
        if(ans.digit < 1)
            ans.digit = 1;
        else
            ans.digit++;

        return ans;
    }

    bool operator >= (Bignum x){
        if(digit > x.digit)
            return true;
        if(x.digit > digit)
            return false;
        for(int i = digit ; i >= 0 ; i--){
            if (num[i] > x.num[i])
                return true;
            else if(num[i] < x.num[i])
                return false;
        }
        return true;
    }

    Bignum operator*(Bignum x){
        Bignum ans;
        for(int i = 0 ; i < digit; i++){
            for(int j = 0; j < x.digit; j++){
                ans.num[i + j] += num[i] * x.num[j];
            }
        }
        for(int i = 0; i < (digit + x.digit + 1); i++){
            ans.num[i + 1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = digit + x.digit + 1;
        while(!ans.num[ans.digit] && ans.digit >= 0)
            ans.digit--;
        if(ans.digit < 1)
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }

    Bignum operator *(int x){
        Bignum ans;
        for(int i = 0; i < digit; i++){
            ans.num[i] = num[i] * x;
        }
        for(int i = 0;i < digit + 1; i++){ // 998
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = digit + 1;
        while(!ans.num[ans.digit] && ans.digit >= 0){
            ans.digit--;
        }
        if(ans.digit < 1)
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }

    Bignum operator /(Bignum x){
        Bignum ans;
        Bignum temp("0");
        for(int i = digit - 1;i >= 0;i--){
            string tempstr = "";
            tempstr += (char)(num[i] + '0');
            temp = temp * 10 + Bignum(tempstr);
            for(int j = 9; j >= 0;j--){
                if(temp >= x * j){
                    temp = temp - x*j;
                    ans.num[i] = j;
                    break; // finished, go next round
                }
            }
        }
        ans.digit = digit; // the most is equal to the dividend
        while(!ans.num[ans.digit] && ans.digit >= 0){
            ans.digit--;
        }
        if(ans.digit < 1)
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }

    void print(){
        if(negative){
            cout << "-";
        }
        for(int i = digit -1; i >= 0; i--){
            cout << num[i];
        }
        cout << endl;
    }
};

int main(){
    string a, b;
    char optr;
    while(cin >> a >> optr >> b){
        Bignum x(a), y(b);
        if(optr == '+'){
            (x + y).print();
        }
        else if(optr == '-'){
            (x - y).print();
        }
        else if(optr == '*'){
            (x * y).print();
        }
        else if(optr == '/'){
            (x / y).print();
        }
    }
}
