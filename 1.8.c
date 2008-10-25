#include <stdio.h>

main()
{
  int c, ntab, nspace,neof;
  ntab = 0;
  nspace = 0;
  neof = 0;

  while ((c=getchar()) != EOF)
  {
    if (c == '\t')
      ++ntab;
    else if (c == ' ')
      ++nspace;
  }
  ++neof;

  printf("tab \t\t space \t\t EOF \n");
  printf("%d \t\t %d \t\t %d \n", ntab, nspace, neof);
}
