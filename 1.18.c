#include <stdio.h>

#define MAXLINE 1000

int getline (char line[], int maxline);
int cleaner (char line[], int size);

main ()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        printf("%s", line);
    return 0;
}


int getline (char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
        printf("%dleng_get: %d\n",i);
    }
    if (c == '\n')  {
        printf("\\n!!!!\n");
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    printf("leng_get: %d\n",i);
    i = cleaner(s, i);
    return i;
}


int cleaner (char str[], int leng)
{
    int i, n;

    for (i=0; i<leng && leng > 3; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (str[i] == str[i-1])
            {
                for (n=i; n<leng; n++)
                {
                    str[n] = str[n+1];
                }
                str[leng-1]='\0';
                leng--;
                i--;
            }

        }
    }

    printf("leng: %d\n", leng);
    if (leng < 2 && str[leng] == '\0')
        leng = 0;
    else if (leng == 3 && str[leng-3] == ' ' && str[leng-1] == '\0')
        leng = 0;


    return leng;
}
