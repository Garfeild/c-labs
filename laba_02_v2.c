/************************************************************
 *  Задание на лабароторную работу №2. Вариант №5.          *
 *  Написать программу, осуществляющую поиск заданного      *
 *  шаблона (последовательности символов) в файле. При      *
 *  обнаружении шаблона заменить его на последовательность  *
 *  символов с кодом 0 такой же длины, что и длина шаблона. *
 ***********************************************************/

/* nullmask */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

//#undef BUFSIZ
//#define BUFSIZ 10


int main(int argc, char *argv[])
{
  register int fd, file, mask;
  register int mlength = 0;
  register int i, k;
  int total;
  char ch;
  char ch2 = '\0';
 
  mask = 0;
  for ( i=0; i<argc; i++)
  {
    if ( argv[i][0] == '-' && argv[i][1] == 'm' ) {
      if ( (argc-i) == 2)
        file = 1;
      else if ( (argc-i) == 3)
        file = 3;
      mask = i+1;
    }
  }

  if ( argc < 4 || argc > 4 ) {
    printf("nullmask: error! no file or mask is specified\n");
    printf("Usage: nullmask /path/to/file  -m <mask>");
    exit(-1);
  }
  else  {
   
    if ( ( fd = open(argv[file], O_RDWR) ) == -1 )  {
      printf("Error: No such file %s.\n", argv[file]);
      exit(-1);
    }
    else {

      mlength = strlen(argv[mask]);  
      while ( read(fd, &ch, 1) != 0) {
        total = 0;
        for(k=0; k<mlength; ++k)  {
          if (ch == argv[mask][k])  {
             read(fd, &ch, 1);
             total++;
             }
        }
        if(total == mlength)  {
          total = 0 - mlength - 1;           
          lseek(fd, total, 1);
          for(k=0; k<mlength; k++)
          write(fd, &ch2, 1);
        }
      }
    }
  }
  
  exit(0);
}

