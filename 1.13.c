#include <stdio.h>

#define N 50 

main()
{
    int c, i, j[N], k, leng[N];
    for (i=0; i<N; i++)
    {
        leng[i] = 0;
        j[i] = 0;
    }

    i = 0;
    k = 0;

    while ((c=getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ' || c == '\r')
        {   if (leng[i] !=0)
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
    
    /*Горизонтальная гистограмма*/
    for (i=0; i<N; i++)
    {
        if (leng[i] != 0)
        {
        printf("word #%d: ", i+1);
            for(k=0; k<leng[i]; ++k)
            {
                putchar('*');
            }
            printf("%d\n", leng[i]);
            j[i] = i+1;
       }
        else
            j[i] = -1;
    }
 
    /*Вертикальная гистограмма*/
    k = 0;

    for(i=0; i<N; i++)
    {
        if(k < leng[i])
        {
            k = leng[i];
        }
    }
    
    while(k!=0)
    {
        printf("%d\t", k);
        for(i=0; i<N;i++)
        {
            if(leng[i] < k)
                printf("\t");
            else 
                printf("*\t");
        }
        putchar('\n');
        k--;
    }

    printf("Word #:\t");
    for(i=0; i<N; i++)
    {
        if(j[i] != -1)
            printf("%d\t", j[i]);
    }
    putchar('\n');
}

