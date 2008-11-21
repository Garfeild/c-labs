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
  int temp = 0;
  int n = 0;
  char ch = '*';
  char ch2 = '!';
  struct stat filest;
  
  if ( argc == 3 )  {
    printf("Process 1, PID %d\n", pid1 = getpid());
    n = (int)atoi(argv[2]);
    printf("%d\n", n);
    if ( (fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, PERMS)) != -1 )  {
      
      fstat(fd, &filest);
      temp = filest.st_atime;
      printf("%d\n", temp);
      if ( (pid2 = fork()) == 0 ) {
        printf("Process 2, PID %d\n", pid2 = getpid());
        while( temp == filest.st_atime ) {
          printf("p2:%d\n", (int)filest.st_atime);
          fstat(fd, &filest);
        }
        
        while( n != 0)  {
          n--;
          write(fd, &ch2, 1);
        }
      }
      else  {
        while( n != 0)  {
          n--;
          write(fd, &ch, 1);
        }
        read(fd, &ch, 1);
        close(fd);
      }
      wait(&st);
    }
  }

  return 0;
}
