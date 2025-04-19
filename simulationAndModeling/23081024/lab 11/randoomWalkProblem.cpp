#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STEPS 100

int main()
{
    int x = 0, y = 0;
    srand(time(0));

    printf("Random Walk (2D) Starting from (0,0):\n");
    printf("Step 0: (%d, %d)\n", x, y);

    for (int i = 1; i <= STEPS; i++)
    {
        int direction = rand() % 4;

        switch (direction)
        {
        case 0:
            y++;
            break;
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            x--;
            break;
        }

        printf("Step %d: (%d, %d)\n", i, x, y);
    }

    printf("Final Position after %d steps: (%d, %d)\n", STEPS, x, y);
    return 0;
}