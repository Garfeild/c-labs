#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  char ch;
  char ch2 = '\r'; //add
  int fd, i, file;
  int toDos = -1;

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
    if ( (fd = open(argv[file], O_RDWR)) == -1) {
      printf("Error: No such file %s\n", argv[file]);
      exit(-1);
    }
    else  {
      while ( (i = read(fd, &ch, 1)) == 1 ) {
        if ( toDos == 1 )  {
          if ( ch == '\n' ) {
            write(fd, &ch2, 1); //add
          }
        }
        else  if ( toDos == 0 ) {
          if ( ch == '\r' ) {
            read(fd, &ch, 1); //add
          }
        }
        write(fd, &ch, 1); //add
      }
      close(fd);
    }
  }
  return 0;
}
