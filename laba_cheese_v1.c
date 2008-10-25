#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  char buf[BUFSIZ];
  char ch;
  int fd, i, file;
  int toDos = -1;
  int total = 0;

  for ( i=0; i<argc; i++)
  {
    if ( argv[i][0] == '-' ) {
      if ( argv[i][1] == 'd' ) 
        toDos = 1;
      else if ( argv[i][1] == 'u' ) 
        toDos = 0;
      if ((argc-i) == 2)
        file = 2;
      else if ( (argc-i) == 1)
        file = 1;
    }
  }
  
  if (argc <3 || argc > 3){
    printf("Error\n");
    exit(-1);
  }
  else   {
    if ( (fd = open(argv[file], O_RDONLY)) == -1) {
      printf("Error: No such file %s\n", argv[file]);
      exit(-1);
    }
    else  {
      while ( (i = read(fd, &ch, 1)) == 1 ) {
        total += i;
        if ( toDos == 1 )  {
          if ( ch == '\n' ) {
            buf[total-1] = '\r';
            total++;
            buf[total-1] = ch;
          }
          else 
            buf[total-1] = ch;
        }
        else  if ( toDos == 0 ) {
          if ( ch == '\r' ) {
            if  (read(fd, &ch, 1) == 1)
                buf[total-1] = ch;
          }
          else 
            buf[total-1] = ch;
        }
      }
      close(fd);
      fd = open(argv[file], O_WRONLY | O_TRUNC);
      if (write(fd, buf, total) != -1)
        close(fd);
      printf("%s\n", buf);
    }
  }
  return 0;
}
