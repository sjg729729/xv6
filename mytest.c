#include "types.h"
#include "user.h"
#include "stat.h"

int main()
{
  int i;
  ps(0);
  for(i = 1; i< 11; i++){
    printf(1, "%d: ", i);
    // getnice의 return 값이 -1 이라면 없는 프로세스임
    if(getnice(i) == -1){
      printf(1, "Wrong pid\n");
    }else{
      printf(1, "setnice %d %d\n", i, i+1);
      setnice(i,i+1);
    }
    ps(i);
  }

  printf(1, "pid1: set nice value to -100\n");
  setnice(1, -100);
  ps(0);

  printf(1, "%d\n", getnice(1));
  printf(1, "%d\n", getnice(2));
  printf(1, "%d\n", getnice(3));

  exit();
}