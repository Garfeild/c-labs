#include <stdio.h>

#define MAXLINE 1000

int getline (char line[], int maxline);
int cleaner (char line[], int size);
void reverse (char line[], int size);

main ()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%s", line);
        reverse(line,len);
        printf("%s", line);
    }
    return 0;
}

int getline (char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')  {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    i = cleaner(s, i);
    return i;
}

int cleaner (char str[], int leng)
{
    int i, n;

    for (i=0; i<leng; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (str[i] == str[i-1])
            {
                for (n=i; n<leng; n++)
                {
                    str[n] = str[n+1];
                }
                str[leng]='\0';
                leng--;
                i--;
            }

        }
    }

    if (leng==2 && str[leng+1] == '\0' && str[leng-1] == ' ')
        leng = 0;
    
   return leng;
}

void reverse (char in[], int leng)
{
    char temp[leng];
    int i;
    
    for (i=0; i<leng;i++)
        temp[i] = in[i];
    
    for(i=0; i<leng-1; i++)
        in[i] = temp[leng-2-i];
    in[leng] = '\0';
}
