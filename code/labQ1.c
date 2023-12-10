#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isPalindrome(char str[])
{
    int size=strlen(str);
    bool flag=true;
    int i=0;
    while(i<size/2)
    {
        if(str[i]!=str[size-i-1])
        {
            return false;

        }
        i++;

    }
    return true;
}
int main()
{

    char string[1000001];
    scanf("%s",string);
    int counta=0;
    int countb=0;
    int i=0;
    int size=strlen(string);
    if(isPalindrome(string))
    {
        printf("Yes\n");
        return 0;
    }
    
    while(1)
    {
        if(string[i]!='a')
        {
            break;
        }
        counta++;
        i++;
        if(i==size-1)
                break;

    }
    i=size-1;

    while(1)
    {
        if(string[i]!='a')
        {
            break;
        }
        countb++;
        i--;
        if(i==0)
        break;
    }
    i=countb-counta;
    //char string1[10000001]='a';
    if(i>0)
    {
       int j=0;
       char new1[size+i+1];
       for(;j<i;j++)
       {
        new1[j]='a';

       }
       for(;j<size+i;j++)
       {
        new1[j]=string[j-i];
       }
       new1[j]='\0';
       if(isPalindrome(new1))
        printf("Yes\n");
       else
        printf("No\n");
    }
    if(i==0)
    {
        if(isPalindrome(string))
        printf("Yes\n");
        else
        printf("No\n");
    
    }
    if(i<0)
    {
        printf("No\n");
    }


    
    return 0;
}
