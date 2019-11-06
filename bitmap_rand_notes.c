#include <stdio.h>

#define X_SIZE 8 /* size of array in the X direction */
#define Y_SIZE 5 /* size of the array in Y direction */
//We use X_SIZE/8 since we pack 8 bits per byte
char graphics[X_SIZE / 8][Y_SIZE]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >>((x)%8))


int main()
{
int loc;  /* current location we are setting */
void print_graphics(void);  /* print the data */   // lmao not necessary for successful compile/run 

//iterates over loc 0-7, when 8 exec print_graphics() & return(0)
for (loc = 0; loc < X_SIZE; ++loc)
    SET_BIT(loc, loc); 
print_graphics();                                // misision ciritical 

return (0);
}


void print_graphics(void)
{
int x; /* current x BYTE */
int y; /* current y location */
unsigned int bit; /* bit we are testing in the current byte */

//create the output matrix
for (y = 0; y < Y_SIZE; ++y)   /* current byte */
    {
    for (x = 0; x < X_SIZE / 8; ++x)   /* bit within current byte */
        {
        for (bit = 128; bit > 0; bit = (bit >> 1))  /* move across the byte, setting bits */
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


/*  DEBUG OBSERVATIONS  */
// void print_graphics(void)

//    x, y, bit
//    0, 0, 128  [10000000], bit=0 > 0, x=1 < 1; printf("\n")
//    0, 1, 64   [01000000], bit=0 > 0, x=1 < 1; printf("\n")
//    0, 2, 32   [00100000], bit=0 > 0, x=1 < 1; printf("\n")
//    0, 3, 16   [00010000], bit=0 > 0, x=1 < 1; printf("\n")







