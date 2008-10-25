#include <stdio.h>

#define N 255 

void print_gist_h(char *s, int c, int n);

main()
{
    int c, i, j, k, numb[N], known[N];
    for (i=0; i<N; i++)
    {
        numb[i] = 0;
        known[i] = -1;
    }

    i = 0;
    j = 0;
    k = 0;


    while ((c=getchar()) != EOF)
    {
        j = 0;
        if (c != '\0' && c != '\n' && c != '\t' && c != ' ' && c != '\r')
        {  
            for (i=0; i<N; i++)
            {
                if (c == known[i])
                {
                    j++;
                    k = i;
                }
                else if (known[i] == -1)
                    k = i;
            }

            if (j == 0)
            {
                known[k] = c;
                numb[k]++;
            }
            else
                numb[k] = numb[k]+j;

        }
    }
    
    printf("Symbols' freq:\n");
    /*Горизонтальная гистограмма*/
    for (i=0; i<N; i++)
    {
        if (numb[i] != 0)
        {
            print_gist_h("symbol \"", known[i], numb[i]);
       }
    }
}

void print_gist_h(char *str, int symbol, int number)
{
    int i;
    printf("%s%c\":\t", str, symbol);
    for(i=0; i<number; i++)
        putchar('*');
    printf("%d\n", number);
}
