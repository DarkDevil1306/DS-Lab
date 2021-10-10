/*Q4. Write a C program to find the frequency of a character present in the te
xt given in a file.
By 2020ITB028_RUPAYAN_THAKUR*/

#include <stdio.h>
int main()
{
 char s[5000];
 int cnt = 0;
 char ch;
 printf("Enter the string:\n");
 gets(s);
 printf("Enter the character whose frequency is to be found: \n");
 scanf("%c", &ch);
 int i = 0;
 while (s[i] != '\0')
 {
 char x;
 x = s[i];
 if (ch == x)
 cnt++;
 i++;
 }
 printf("Frequency of ' %c ' : %d \n", ch, cnt);
} 