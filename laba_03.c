/************************************************************
 *  Задание на лабароторную работу №3. Вариант №5.          *
 *  Процесс 1 открывает файл и порождает потомка 2, после   *
 *  этого пишет в файл N байт, закрывает его и завершается. *
 *  Потомок процесс 2 пишет N байт в файл, закрывает его и  *
 *  завершается. Для определения очередности записи         *
 *  использовать функцию fstat.                             *
 ***********************************************************/

/* forki */

#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define PERMS 0666
int main (int argc, char *argv[])
{
  int pid1, pid2, st, fd;
  int n = 0;
  char ch = '*';
  char ch2 = '!';
  struct stat filest;
  struct stat temp2;
  
  if ( argc == 3 )  {
    printf("Process 1, PID %d\n", pid1 = getpid());
    n = (int)atoi(argv[2]);
    if ( (fd = open(argv[1],  O_RDWR )) == -1 ) {
      if ( (fd = open(argv[1], O_CREAT| O_RDONLY, PERMS)) == -1)  {
        printf("Error: can't open file %s\n", argv[1]);
        exit(-1);
      }
      else  {
        sleep(1);
        close(fd);
      }
    }
    fd = open(argv[1], O_RDWR | O_TRUNC);
    fstat(fd, &filest);
    temp2 = filest;
    
    if ( (pid2 = fork()) == 0 ) {
      printf("Process 2, PID %d\n", pid2 = getpid());
      while( (int)temp2.st_mtime == (int)filest.st_mtime && (int)temp2.st_atime == (int)filest.st_atime )  {
        fstat(fd, &filest);
        }
      
      printf("Process 2 is writing\n");
      while( n != 0)  {
        n--;
        write(fd, &ch2, 1);
      }
    }
    else  {
      printf("Process 1 is writing\n");
      while( n != 0)  {
        n--;
        write(fd, &ch, 1);
      }
      read(fd, &ch, 1);
      close(fd);
    }
    wait(&st);
  } 
  else  {
    printf("Error!\n\tUsage: forki /path/to/file <number of bytes>\n");
    exit(-1);
  }

  return 0;
}
