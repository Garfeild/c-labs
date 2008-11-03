#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  char ch;
  char ch2 = '\r'; //add
  int fd, i, file, fd2;
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
     if ( (fd = open(argv[file], O_RDONLY)) == -1 && (fd2 = open(argv[file], O_WRONLY) == -1)) {
      printf("Error: No such file %s\n", argv[file]);
      exit(-1);
    }
    else  {
      while ( (i = read(fd, &ch, 1)) == 1 ) {
        if ( toDos == 1 )  {
          if ( ch == '\n' ) {
            printf("found\n");
            write(fd2, "\r", 1); //add
            write(fd2, "\r", 1); //add
          }
        }
        else  if ( toDos == 0 ) {
          if ( ch == '\r' ) {
            read(fd, &ch, 1); //add
            write(fd2, &ch, 1); //add
          }
        }
        //lseek(fd, -1, 1);
        //write(fd2, &ch, 1); //add
      }
      close(fd);
      close(fd2);
    }
  }
  return 0;
}
