#include "types.h"
#include "stat.h"
#include "user.h"


int 
main(int argc, char **argv) 
{
  if(argc != 2){
    printf(2, "No input pid ...\n");
    exit();
  }

  ps(atoi(argv[1]));
  exit();
}