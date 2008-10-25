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

void fndarplc(char*, char*);

int main(int argc, char *argv[])
{
  register int fd, file, mask;
  register int mlength = 0;
  register int i, k;
  char buf[BUFSIZ];
 
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
   
    if ( ( fd = open(argv[file], O_RDONLY) ) == -1 )  {
      printf("Error: No such file %s.\n", argv[file]);
      exit(-1);
    }
    else {

      mlength = strlen(argv[mask]);
      
      if ( (i = read (fd, buf, BUFSIZ)) < BUFSIZ ) {
        fndarplc(buf, argv[mask]);
        
        close(fd);
        fd = open (argv[file], O_WRONLY | O_TRUNC);
        write(fd, buf, i);
      }
      else if ( i < mlength )
        ;
      else if ( i == BUFSIZ ) {
        k = lseek(fd, 0.0, 2);

        char *tmpstr = (char*) malloc( sizeof(char) * k);
       
        lseek(fd, 0.0, 0);
        i = read(fd, tmpstr, k);

        fndarplc(tmpstr, argv[mask]);
        
        close(fd);
        if ( (fd = open (argv[file], O_WRONLY | O_TRUNC)) != -1)  {
          write(fd, tmpstr, i);   
        }
        else 
          printf("Error: unable to write\n");
      }
    }
    close(fd);
  }
  
  exit(0);
}

void fndarplc(char *str, char *sub)
{
  register int i=0;
  register int count=0;
  register int k = strlen(str);

  for ( i = 0; i < k; i++ ) {
    if ( str[i] == sub[0] )  {
      count=0;
      while ( str[i+count] == sub[count]) {
        count++;
      }
      
      if ( count == (strlen(sub)) ) {
        while (count > 0 ) {
        str[i+count-1] = '\0';
        count--;
        }
      }
    }
  }
}

