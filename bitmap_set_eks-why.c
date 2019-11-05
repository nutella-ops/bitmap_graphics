#include <stdio.h>

// #define X_SIZE 8 /* size of array in the X direction */
// #define Y_SIZE 5 /* size of the array in Y direction */


//We use 8/8 since we pack 8 bits per byte

char graphics[8 / 8][5];                           /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >>((x)%8))

int main()
{
int coord;                                         /* current coordinate we are setting */
void print_graphics(void);                         /* print the data */

// for (coord = 0; coord < 8; ++coord)
//     SET_BIT(coord, coord);
//     print_graphics();

int eks = 4;
int why = 5;
    
SET_BIT(eks, why);
print_graphics();
    
return (0);
}
                                                //   _______________________________________________
                                                // * print_graphics -- print the graphics bit array *
                                                // * as a set of 1s and 0s.                         *
                                                // *________________________________________________*

void print_graphics(void)                         /* function for visual output */                           
{
int x;                                            /* current x byte */
int y;                                            /* current y location */
unsigned int bit;                                 /* bit we are testing in the current byte */


for (y = 0; y < 5; ++y)                           /* create the output matrix */
{
    for (x = 0; x < 8 / 8; ++x) 
    {
    for (bit = 0x80; bit > 0; bit = (bit >> 1))   /* Handle each bit */ 
        {
        if ((graphics[x][y] & bit) != 0)
        printf("1");
        else
        printf("0");
        }
    }
printf("\n");
}
}
