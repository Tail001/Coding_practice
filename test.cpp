#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string, string);
string sum(string, string);
string min(string, string);
string mul(string, string);
string div(string, string);

int main(){
    //ios::sync_with_stdio (false);
    //cin.tie(0);
    string a, b, s;
    char c;
    while(cin>>a>>c>>b){
        if(c=='+')
            s = sum(a, b);
        if(c=='-')
            s = min(a, b);
        if(c=='*')
            s = mul(a, b);
        if(c=='/')
            s = div(a, b);
        // if(c == 'x')
        //     cout << cmp(a, b) << endl; 
        // cout << s << endl;
    }

    return 0;
}

bool cmp(string a, string b){
    if(a.length()!=b.length())
        return a.length() > b.length();
    for (int i = 0; i < a.length();i++){
        if(a[i]!=b[i])
            return a[i] > b[i];
    }
    return true;
}

string sum(string a,string b){
    string k;
    if(b.length()>a.length())
        swap(a, b);
    char c[a.length()], d[a.length()], s[a.length()];
    for (int i = 0; i < a.length();i++){
        c[i] = a[i];
        if(a.length()-i>b.length())
            d[i] = '0';
        else
            d[i] = b[b.length()-(a.length()-i)];
    }
    int n=0,r=0;
    for (int i = a.length() - 1; i >= 0;i--){
        n = c[i] -'0'+ d[i] -'0'+ r;
        if(n>=10){
            n = n - 10;
            r = 1;
        }
        else
            r = 0;
        s[i] = n + '0';
    }
    if(r==1)
        k += '1';
    for (int i = 0; i < sizeof(s);i++){
        k += s[i];
    }
    return k;
}

string min(string a,string b){
    string k;
    bool j = cmp(a, b);
    if(j==false){
        swap(a, b);
        k += '-';
    }
    char c[a.length()], d[a.length()], s[a.length()];
    for (int i = 0; i < a.length();i++){
        c[i] = a[i];
        if(a.length()-i>b.length())
            d[i] = '0';
        else
            d[i] = b[b.length()-(a.length()-i)];
    }
    int n=0,r=0;
    for (int i = a.length() - 1; i >= 0;i--){
        n = c[i] - d[i] + r;//為何不用-'0'
        if(n<0){
            n = n + 10;
            r = -1;
        }
        else
            r = 0;
        s[i] = n + '0';
    }
    bool j2 = false;
    for (int i = 0; i < sizeof(s);i++){
        if(s[i]!='0')
            j2 = true;
        if(j2)
            k += s[i];
    }
    if(j2 == false)
        k += '0';
    return k;
}

string mul(string a, string b){
    string k;
    int l = a.length() + b.length();
    int s[l],c[a.length()],d[b.length()];
    for (int i = 0; i < l;i++) s[i] = 0;
    for (int i = 0; i < a.length();i++) c[i]=a[i]-'0';
    for (int i = 0; i < b.length();i++) d[i]=b[i]-'0';
    for (int i = a.length() - 1; i >= 0; i--){
        for (int j = b.length() - 1; j >= 0; j--){
            if(i+j>=0)
                s[i+j+1] += c[i] * d[j];
        }
    }
    for (int i = l-1; i > 0;i--){
        if(s[i]>=10){
            s[i - 1] += s[i] / 10;
            s[i] %= 10;          
        }
    }
    for (int i = 0; i < l;i++){
        if(i==0 && s[i]==0)
            continue;
        k += (s[i]+'0');
    }
    return k;
}

string div(string a, string b){
    if(!cmp(a,b)){
        cout << " hello" << endl;
        return "0";
    }
    string c,k;
    int t;
    while(cmp(a,b)){ // if a > b or not　
        c.clear();
        if((a[0]-'0')/(b[0]-'0')!=0){
            c += (a[0] - '0') / (b[0] - '0')+'0';
            for (int i = 0; i < a.length() - b.length();i++) c+='0';
            cout << c << endl;
        }
        else{
            int num = 0;
            num = a[0] - '0'; // number
            while(num/b[0]==0){
                t++;
                num = num * 10 + (a[t]-'0');
            }
            c += num / (b[0] - '0') + '0';
            for (int i = 0; i < a.length() - b.length() - t; i++) c += '0';
        }
        t = 0;
        while(!cmp(a,mul(b,c))){
                c[t]--;
                if(c[t]=='0'){
                    ++t;
                    c[t] = '9';
                } 
        }
        a = min(a, mul(b, c));
        k = sum(k, c);
    }
    return k;
}

