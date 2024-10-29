#include "types.h"
#include "stat.h"
#include "user.h"

void testcfs()
{
    int parent = getpid();
    int child;
    int i;
    double x = 0, z;
    // int parent_first = 0;

    if((child = fork()) == 0) { // child
        setnice(parent, 9);

        for(i = 0; i < 3000; i++){
            // if(i == 0)
            //     printf(1, "Child start... parent is %d\n", parent_first);

            for ( z = 0; z < 30000.0; z += 0.1 )
                x =  x + 3.14 * 89.64;

            if(i % 200 == 0)
                printf(1, "child loop %d\n", i);
        }
        printf(1, "*** Child process finished... -> %d\n", getpid());
        ps(0);
        exit();
   } else {
        // sleep(3);
        // printf(1, "*** Parent process.. -> %d\n", getpid());
        setnice(child, 0);     //parent
        for(i = 0; i < 3000; i++){
            for ( z = 0; z < 30000.0; z += 0.1 ){
                x =  x + 3.14 * 89.64;
                // parent_first++;
            }
                
            if(i % 200 == 0)
                printf(1, "parent loop %d\n", i);
        }

        printf(1, "*** Parent process finished... -> %d\n", getpid());
        ps(0);
        wait();
   }
}
int main(int argc, char **argv)
{       
    printf(1, "=== INIT ===\n");
    ps(0);
    printf(1, "=== TEST START ===\n");
    testcfs();
    printf(1, "=== TEST   END ===\n");
    ps(0);
    exit();
}