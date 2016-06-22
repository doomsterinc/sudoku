#include <stdio.h>#include <stdlib.h>
#include <time.h>
#define size 9
 
 
//function 1
int obeysSudokuRules(int a[][size])
{
    int count[10];
    int i,r,c,z;//r: row, c: column
    int k=0; //No. of rows in a grid
    int j=0; // No. of columns in a grid
    for ( r=0; r<size; r++) //start from 1st row checking colums
    {
        for( c=0; c<size; c++)
        {
            count[a[r][c]]++;
        if ( (count[a[r][c]]) > 1)
         return 0; 
        }
        for (i=0; i<size; i++)
        { count[i]=0; } // to clear
         }//end row loop
     
    for (i=0; i<size; i++)
    { count[i]=0; } // to clear
 
 
//start from 1st col checking rows
    for ( c=0; c<size; c++) 
    {
        for( r=0; r<size; r++)
        {
            count[a[r][c]]++;
        if ( (count[a[r][c]]) > 1)
            return 0;
        }
            for (i=0; i<size; i++)
        { count[i]=0; } // to clear
         }//end col loop
     
        for (i=0; i<size; i++)
        { count[i]=0; } // to clear
//z is No. of grids
    r=0; c=0;
    for ( z=0; z<size; z++) 
    {
        //int k=0; //No. of rows in a grid
        //int j=0; // No. of columns in a grid
        while (k<3)
        {
            while(j<3)
            {
                count[a[r][c]]++;
                 
                if ( (count[a[r][c]]) > 1)
                    return 0;
                c++; j++;
            } //end of j loop
            r++; k++;
        } // end of k loop
        if(z<2)
        { r=0; }
        if(z==2)
        { c=0; r=3; }
        if((z>2)&&(z<5))
        { r=3; }
        if(z==5)
        { c=0; r=6; }
        if(z>5)
        { r=6; }
 
 
        for (i=0; i<size; i++)
            { count[i]=0; } // to clear & end z loop
    return 1;
    } }// end grid loop
 
 
//function 2
void printGrid(int a[][size])
{
    int r, c;
 
 
    for(r=0; r<size; r++)
    {
        for(c=0; c<size; c++)
        {
            if ((a[r][c])== 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d",a[r][c]);
            }
            printf("\n");
        }
    }
}
//function 3 calls this  (a)                          
int genGrid(int a[][size], int row, int column)
{ 
    int i, r; int swap;
    int currentRow[size]={1,2,3,4,5,6,7,8,9};
    int obyesRules;
 
 
    if (row == size)
    return 1;
   
   for(i=0;i<size-1;i++)
   {
    r= i+ (rand()%8);
    swap=currentRow[i];
    currentRow[i]=currentRow[r];
    currentRow[r]=swap;
   }
    
   for(i=0;i<size;i++)
   {
    a[row][column] = currentRow[i];
    if (obeysSudokuRules==1)
    {
        if (column == size -1)
            obyesRules = genGrid(a, row + 1, 0);
        else
            obyesRules = genGrid(a, row, column + 1);
        if(obyesRules)
            return 1 ;
    } // close inner if statement
    } // close for loop
    
   a[row][column] = 0;
    
   return 0 ;
}
// function 3 call this (b)
void fillZeros (int a[][size])
{
    int counter=0;
    int r,random;
 
 
    for(r=0; r<size; r++)
    {
        while (counter<=4)
        {
            random= (rand()%8);
            a[r][random]=0;
            counter++;
        }
    }
}
 
 
//function 3
void genPartialGrid(int a[][size])
{    
    int obeysRules; int r, c;
     
   do{
       for(r=0; r<size; r++)
       {
           for(c=0; c<size ;c++)
               a[r][c]= 0;  //Fill array a with all zeros
       }
        obeysRules = genGrid(a, 0, 0);
      
   } while (obeysRules == 0);
 
 
   fillZeros(a);
}
 
 
//function 5 &4
int getRowNum(void)
{
    int row;
    printf(" please enter the row number that you want to enter the value\n");
    scanf("%d",row);
 
 
    while ((row <0) || (row>8))
    {
        printf(" please enter the row number that you want to enter the value");
        scanf("%d",&row);
    }
    return row;
}
 
 
int getColumnNum(void)
{
    int column;
    printf(" please enter the column number that you want to enter the value");
    scanf("%d",&column);
 
 
    while ((column<0) || (column>8))
    {
        printf(" please enter the row number that you want to enter the value");
        scanf("%d",column);
    }
    return column;
}
//function 6
int getValue(void)
{
int value;
printf("\nPlease Enter the value: ");
scanf("%d",&value);
return value;
}
 
 
 
 
int compSolve(int a[][size])
   {
       int r = 0; int c = 0;
       int checkZero;
       while(r<9)
       {
           while(c<9)
           {
               if((a[r][c])==0)
                   checkZero = 0;
               else checkZero = 1;
               c++;
           }
       r++;
       }
       return checkZero;
   }
 
 
 
 
int main(void)
{
int a[size][size];
int r,c, value, obey, solve;
srand(time(NULL)); //to randomize random number generation
 
 
printf("This a sudoku Game.All numbers in rows and columns must not be repeated");
 
 
genPartialGrid(a);     //call function genPartialGrid to generate a partially filled grid that does not violate Sudoku rules
 
 
printGrid(a);          //call function printGrid
 
 
do
{
 
 
r = getRowNum();              //call function getRowNum to determine the row number
c = getColumnNum();           //call function getColumnNum to determine the column number
value = getValue();
printGrid(a);   //call function to get the value (between 1 and 9) 
a[r][c] = value;              //enter the value in the grid at the row and column positions entered
                              //call function printGrid
obey = obeysSudokuRules;
solve = compSolve;
 
 
} while ((obey ==1) && (solve == 0));
 
 
if ((solve == 1) && (obey == 1))
{
    printf("congratulation,you have solve the puzzle");
    printGrid(a);
}
else                                   /* it means Sudoku rules are not all obeyed */
{
    printf(" Sorry, the Solution is incorrect");
}
printf(" thank you, good bye");
 
 
return 0;
}