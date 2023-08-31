/*
Description: 
    #include <stdio.h>
    int input(char str[]);
    void output(char s[], int len);
    int is_palindrome(char s[], int len);

    int main(){
    char str[22];
    int len=1;

    len = input(str);
    if(-1 == len){
        printf("invalid input\n");
        return 0;
    }

    output(str, len);
    
    if (is_palindrome(str,len))
        printf("a palindrome\n");
    else
        printf("not a palindrome\n");
    
    return 0;
    }

    int input(char str[]){
    int len=1;
    char temp_c;
    int i=0;

    do{
        scanf("%c", &temp_c);
        if(temp_c!=' ' && temp_c!='\n')
        str[i] = temp_c;
        i++;
    } while(temp_c!=' ' && temp_c!='\n' && i<22);
    len = i-1;
    if(i>20){
        printf("invalid input\n");
        len= -1;
    }
    return len;
    }

Sample: 
    sample input 1
    aba
    sample output 1
    aba
    a palindrome
    
*/

#include <stdio.h>
int input(char str[]);
void output(char s[], int len);
int is_palindrome(char s[], int len);

int main(){
    char str[22];
    int len=1;

    len = input(str);
    if(-1 == len){
        printf("invalid input\n");
        return 0;
    }

    output(str, len);

    if (is_palindrome(str,len))
        printf("a palindrome\n");
    else
        printf("not a palindrome\n");

    return 0;
}

int input(char str[]){
    int len=1;
    char temp_c;
    int i=0;

    do{
        scanf("%c", &temp_c);
        if(temp_c != ' ' && temp_c!='\n')
        str[i] = temp_c;
        i++;
    } while(temp_c!=' ' && temp_c!='\n' && i<22);
    len = i-1;
    if(i>20){
        printf("invalid input\n");
        len= -1;
    }
    return len;
}

void output(char s[], int len){
    for(int i = 0; i < len; i++){
        printf("%c", s[i]);
    }
    printf("\n");
}
int is_palindrome(char s[], int len){
    int i = 0;
    while(s[i] == s[len-1-i] && i<=len){
        i++;
    }
    if(i == 0){
        return 0;
    }
    else if(i - len == 0){
        return 1;
    }
}
