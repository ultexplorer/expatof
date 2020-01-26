#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double expatof(char s[]);
int dec(int exp);

int main()
{
    char str[MAXLINE]="  1.111e3";
    double N=expatof(str);
    printf("%f\n", N);

    int x=0;
    int y=dec(x);
    printf("%d\n", y);
    
    return 0;
}

double expatof(char s[])
{
    int i, sign, esign, eval;
    double val, power;
    for(i=0; isspace(s[i]); i++); // пропуск пробелов;

    sign=(s[i]=='-')? -1 : 1;
    
    if(s[i]=='-' || s[i]=='+') i++;

    for(i, val=0.0; s[i]!='.' && s[i]!='\0' && s[i]!='e'; i++){
         val=10.0*val + (s[i]-'0');
    }
    if(s[i]=='.'){
        i++;
    }
    for(power=1.0; s[i]!='\0' && s[i]!='e'; i++)
    {
        val=10.0*val+(s[i]-'0');
        power*=10;
    }

    if(s[i]=='e'){
        i++;
        if(s[i]=='-'){
            i++;
            esign=-1;
        }
        else{
            esign=1;
        }
        for(eval=0; s[i]!='\0'; i++){
            eval=10*eval+(s[i]-'0');
        }
        if(esign==-1)
        {
            return sign*val/(power*dec(eval));
        }
        else
        {
            return sign*val*dec(eval)/power;
        }        
    }

    return sign*val/power;
}

int dec(int exp)
{
    int rezult=1;
    for(int i=0; i<exp; i++){
       rezult*=10;
    }
    return rezult;
}