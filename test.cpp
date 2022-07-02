//http://maplewing.blogspot.com/2011/07/zerojudgea021.html
#include<iostream>
#include <typeinfo>
using namespace std;

class bignum
{
    public:
    int num[1000];
    int digit;
    int negative;

    bignum()
    {
        digit = 1;
        for( int i = 0 ; i < 1000 ; i++ )
            num[i] = 0;
        negative = 0;
    }
    
    bignum( string s )
    {
        digit = s.length();
        for( int i = 0 ; i < s.length() ; i++ )
            num[i] = s[s.length()-i-1] - '0'; // convert into integer, but it is still string
            // store reversily
        for( int i = s.length() ; i < 1000 ; i++ )
            num[i] = 0;       
        negative = 0; 
    }
    // operator overloading
    bignum operator+( bignum x )
    {
        bignum ans;
        int max_digit = max( digit, x.digit );

        for( int i = 0 ; i < max_digit ; i++ )
        {
            ans.num[i] += num[i] + x.num[i];
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = max_digit + 1; // 進位的問題
        while( !ans.num[ans.digit] && ans.digit >= 0 ){
            ans.digit--;
		}

        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans; // return all whole  bignum datatype
    }
    
    bignum operator-( bignum x )
    {
        bignum ans;
        int max_digit = max( digit, x.digit );
        if( *this >= x ) // bigger minus smaller
        {
            for( int i = 0 ; i < max_digit ; i++ )
            {
                ans.num[i] = num[i] - x.num[i];
            }
            
        }
        else // smaller minus bigger
        {
            for( int i = 0 ; i < max_digit ; i++ )
            {
                ans.num[i] = x.num[i] - num[i];
            }
            ans.negative = 1; // this number is negative
        }
        for( int i = 0 ; i < max_digit ; i++ )
        {
            if( ans.num[i] < 0 )
            {
                ans.num[i+1]--;
                ans.num[i] += 10;
            }
        }
        ans.digit = max_digit;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bignum operator*( bignum x )
    {
        bignum ans;
        for( int i = 0 ; i < digit ; i++ )
            for( int j = 0 ; j < x.digit ; j++ )            
            ans.num[i+j] += num[i] * x.num[j];

        for( int i = 0 ; i < digit+x.digit+1 ; i++ )
        {
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = digit+x.digit+1;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bignum operator*( int x )
    {
        bignum ans;
        for( int i = 0 ; i < digit ; i++ )          
            ans.num[i] += num[i] * x;
        for( int i = 0 ; i < 998 ; i++ ) //997 remain for 進位
        {
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = 999;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bool operator>=( bignum x )
    {
        if( digit > x.digit )
            return true;
        if( digit < x.digit )
            return false;
        for( int i = digit ; i >= 0 ; i-- )
            if( num[i] > x.num[i] )
                return true;
            else if( num[i] < x.num[i] )
                return false;
                
        return true;
    }
    
    bignum operator/( bignum x )
    {
        bignum temp("0");// 初始化
        bignum ans;
        for( int i = digit-1 ; i >= 0 ; i-- )
        {
            string tempstr = "";
            tempstr += (char)(num[i]+'0'); //convert int to char
            temp = temp * 10 + bignum(tempstr);
            for( int j = 9 ; j > 0 ; j-- )
            {
                if( temp >= x*j )
                {
                    temp = temp - x*j;
                    ans.num[i] = j;
                    break;
                }
            }
        }
        ans.digit = digit;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    void print()
    {
        if( negative )
            cout << '-';
        for( int i = digit-1 ; i >= 0 ; i-- ) //print reversily
            cout << num[i];
        cout << endl;
    }
};

int main()
{
    string a, b;
    char ope;
    while( cin >> a >> ope >> b )
    {
        bignum x(a), y(b);
        if( ope == '+' )
        {
            (x+y).print(); //type : bignum
        }
        else if( ope == '-' )
        {
            (x-y).print();
        }
        else if( ope == '*' )
        {
            (x*y).print();
        }
        else if( ope == '/' )
        {
            (x/y).print();
        }
    }
    return 0;
}