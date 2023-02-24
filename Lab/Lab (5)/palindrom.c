#include<stdio.h>
#include<string.h>
int main()
{
    char s[120], t , s1[120];
    int i=0, j = 0;
    printf("Enter String : ");
    gets(s);  
    strcpy(s1,s);
    j = strlen(s) - 1;
    while (i < j)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
    printf("\nReverse String = %s", s);
    if(strcmp(s,s1)==0)
    printf("\n\n%s is Palindrome",s1);
    else
    printf("\n\n%s is Not Palindrome",s1);
    return (0);
}
