#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int main(){
  struct stat *x = malloc(sizeof(struct stat));
  stat("statFunctions.c", x);

  if (stat("statFunctions.c", x) != 0){
    printf("errno: %d error\n", errno);
  }

  printf("\nPRINTING STATFUNCTIONS.C INFO...\n");

  //testing file size
  printf("%s is %lld bytes long.\n", "statFunctions.c", x->st_size);

  //testing permissions
  printf("%s permissions: %hu\n", "statFunctions.c", x->st_mode);

  //testing time of last access
  char *t = ctime(&x->st_atime);
  printf("%s was last accessed on %s\n", "statFunctions.c", t);

  //testing human readable form
  printf("PRINTING STATFUNCTIONS.C SIZE IN HUMAN READABLE FORM...\n");
  long long length = x->st_size;
  char b[50];
  sprintf(b, "%lldB\t%fKB\t%fMB\t%fGB\n\n", length, (double)length/1000, (double)length/1000000, (double)length/1000000000);
  printf("%s", b);


}
