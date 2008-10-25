#include <stdio.h>

main()
{
  int c;

  while ((c=getchar()) != EOF)
  {
      if (c == '\t')
      {
          c = 't';
          putchar('\\');
      }
      else if (c == '\b')
      {
          c = 'b';
          putchar('\\');
      }
      else if (c == '\\')
      {
          c = '\\';
          putchar('\\');
      }
      putchar(c);
  }
}
