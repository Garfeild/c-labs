#include <stdio.h>

#define N 50 

void print_gist_h(char *s, int l, int len);

main()
{
    int c, i, j, leng[N];
    for (i=0; i<N; i++)
    {
        leng[i] = 0;
    }

    i = 0;
    j = 0;

    while ((c=getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ' || c == '\r')
        {  

            ++i;
        }
        else if (i == N)
        {
            printf("Error: Maximum %d words\n", N);
            exit(-1);
        }
        else
            ++leng[i];
    }
    
    printf("Words' length:\n");
    /*Горизонтальная гистограмма*/
    for (i=0; i<N; i++)
    {
        if (leng[i] != 0)
        {


            print_gist_h("Word #", i+1, leng[i]);
       }
    }
}

void print_gist_h(char *str, int line, int length)
{
    int i;
    printf("%s%d:\t", str, line);
    for(i=0; i<length; i++)
        putchar('*');
    printf("%d\n", length);
}
