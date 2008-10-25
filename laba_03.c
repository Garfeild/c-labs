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

int main (int argc, char *argv[])
{
  int pid1, pid2, st, fd;
  int i;
  char buf[BUFSIZ];
  
  //if ( argc == 2 )
  //{
    printf("Process 1, PID %d\n", pid1 = getpid());
    if ( (pid2 = fork()) == 0 )
    {
      printf("Process 2, PID %d\n", pid2 = getpid());
      wait(&st);
    }

    if ( (fd = open(argv[1], O_RDONLY)) != -1 )
    {
      i = read(fd, buf, BUFSIZ);
      printf("%d\n", pid1);
      printf("String from file:\n%s\n", buf);
    }
    close(fd);


  //}
  return 0;
}
