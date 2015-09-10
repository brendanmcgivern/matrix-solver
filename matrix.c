#include<stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

void multiplyRow(float m[MAX_ROWS][MAX_COLS],int row_index,float coefficient,int r,int c);
void readMatrix(float [MAX_ROWS][MAX_COLS],int *r,int *c);
void rowReduce(float [MAX_ROWS][MAX_COLS],int r,int c);
void printMatrix(float [MAX_ROWS][MAX_COLS],int r,int c);
void subtractRow(float [MAX_ROWS][MAX_COLS],int row_index_changed,int row_index,int r,int c);
void swapInNonZeroRow(float m[MAX_ROWS][MAX_COLS],int row_index,int r,int c);

void AddMatrix(void);
void SubtractMatrix(void);
void MultiplyMatrix(void);
void TransposeMatrix(void);

int main(void)
{
    int n2;

    int r, c, n, i, j;
    float m[MAX_ROWS][MAX_COLS], temp[MAX_ROWS][MAX_COLS], sum[MAX_ROWS][MAX_COLS];

    printf("\tWelcome to the matrix solver!\n\n");

    while(n2 != 6)
    {
        printf("\n");
        printf("Choose a function from the following options:\n\n");
        printf("1 - Add two matrices\n");
        printf("2 - Subtract two matricies\n");
        printf("3 - Multiply two matricies\n");
        printf("4 - Transpose a matrix\n");
        printf("5 - Solve an augmented matrix in row echelon form\n");
        printf("6 - Exit\n\n");

        scanf("%d", &n2);

        switch(n2)
        {
            case 1:
                AddMatrix();
                break;

            case 2:
                SubtractMatrix();
                break;

            case 3:
                MultiplyMatrix();
                break;

            case 4:
                TransposeMatrix();
                break;

            case 5:
                readMatrix(m,&r,&c);
                rowReduce(m,r,c);
                break;

            case 6:
                printf("\n");
                printf("Thank you for using the Matrix Solver.  Goodbye!\n");
                break;
        }
    }

return 0;
}

void MultiplyMatrix(void)
{
  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];

  printf("Enter the number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter the elements of first matrix\n");

  for (  c = 0 ; c < m ; c++ )
    for ( d = 0 ; d < n ; d++ )
      scanf("%d", &first[c][d]);

  printf("Enter the number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);

  if ( n != p )
    printf("Matrices with entered orders can't be multiplied with each other.\n");
  else
  {
    printf("Enter the elements of second matrix\n");

    for ( c = 0 ; c < p ; c++ )
      for ( d = 0 ; d < q ; d++ )
        scanf("%d", &second[c][d]);

    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      {
        for ( k = 0 ; k < p ; k++ )
        {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }

    printf("Product of entered matrices:\n");

    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
        printf("%d  ", multiply[c][d]);

      printf("\n");
    }
  }
}

void AddMatrix(void)
{
   int m, n, c, d, first[10][10], second[10][10], sum[10][10];

   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", &m, &n);
   printf("Enter the elements of first matrix\n");

   for ( c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
         scanf("%d", &first[c][d]);

   printf("Enter the elements of second matrix\n");

   for ( c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
            scanf("%d", &second[c][d]);

   for ( c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
         sum[c][d] = first[c][d] + second[c][d];

   printf("Sum of entered matrices:-\n");

   for ( c = 0 ; c < m ; c++ )
   {
      for ( d = 0 ; d < n ; d++ )
         printf("%d\t", sum[c][d]);

      printf("\n");
   }
}

void SubtractMatrix(void)
{
     int m, n, c, d, first[10][10], second[10][10], difference[10][10];

  printf("Enter the number of rows and columns of matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter the elements of first matrix\n");

  for (c = 0; c < m; c++)
    for (d = 0 ; d < n; d++)
      scanf("%d", &first[c][d]);

  printf("Enter the elements of second matrix\n");

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
        scanf("%d", &second[c][d]);

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      difference[c][d] = first[c][d] - second[c][d];

  printf("difference of entered matrices:-\n");

  for (c = 0; c < m; c++)
  {
    for (d = 0; d < n; d++)
      printf("%d\t",difference[c][d]);

    printf("\n");
  }
}

void TransposeMatrix(void)
{
     int m, n, c, d, matrix[10][10], transpose[10][10];

   printf("Enter the number of rows and columns of matrix ");
   scanf("%d%d",&m,&n);
   printf("Enter the elements of matrix \n");

   for( c = 0 ; c < m ; c++ )
   {
      for( d = 0 ; d < n ; d++ )
      {
         scanf("%d",&matrix[c][d]);
      }
   }

   for( c = 0 ; c < m ; c++ )
   {
      for( d = 0 ; d < n ; d++ )
      {
         transpose[d][c] = matrix[c][d];
      }
   }

   printf("Transpose of entered matrix :-\n");

   for( c = 0 ; c < n ; c++ )
   {
      for( d = 0 ; d < m ; d++ )
      {
         printf("%d ",transpose[c][d]);
      }
      printf("\n");
   }
}


void readMatrix(float m[MAX_ROWS][MAX_COLS],int *r,int *c)
{
    int i,j;
   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", r, c);
   printf("Enter the elements of the matrix\n");

    for ( i = 0 ; i < *r ; i++ )
    {
      for ( j = 0 ; j < *c ; j++ )
      {
         scanf("%f", &m[i][j]);
      }
    }
    printf("\n");

}

void multiplyRow(float m[MAX_ROWS][MAX_COLS],int row_index,float coefficient,int r,int c)
{
    int j;
    for (j=0;j<c;j++)
        m[row_index][j]*=coefficient;
}

void rowReduce(float m[MAX_ROWS][MAX_COLS],int r,int c)
{
    int i,i2;
    for (i2=0;i2<r;i2++)
    {
        if (i2>=c)
            break;

        swapInNonZeroRow(m,i2,r,c);

        printf("R%d(%f) -> R%d:\n",i2+1,1/m[i2][i2],i2+1);

        if (m[i2][i2]==0)
        {
            printf("No solution.\n");
            return;
        }
        multiplyRow(m,i2,1/m[i2][i2],r,c);

        printMatrix(m,r,c);
        printf("\n");

        // process previous rows.
        for (i=0;i<i2;i++)
        {
            if (m[i][i2]!=0)
            {
                float f=m[i][i2];
                multiplyRow(m,i2,f,r,c); // row[i2]*=f
                subtractRow(m,i,i2,r,c); // row[i]-=row[i2]
                multiplyRow(m,i2,1/f,r,c); // restore old row with leading 1

                printf("R%d(%f)+R%d -> R%d:\n",i2+1,-f,i+1,i+1);
                printMatrix(m,r,c);
                printf("\n");
            }
        }

        // process next rows.
        for (i=i2+1;i<r;i++)
        {
            if (m[i][i2]!=0)
            {
                float f=m[i][i2];
                multiplyRow(m,i2,f,r,c);
                subtractRow(m,i,i2,r,c);
                multiplyRow(m,i2,1/f,r,c); // bring back to 1.

                printf("R%d(%f)+R%d -> R%d:\n",i2+1,-f,i+1,i+1);
                printMatrix(m,r,c);
                printf("\n");
            }
        }

        printf("After column %d solved.\n\n",i2+1);
    }
    printMatrix(m,r,c);
}

void printMatrix(float m[MAX_ROWS][MAX_COLS],int r,int c)
{
    int i,j;

        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                printf("%f\t",m[i][j]);
            }
            printf("\n");
        }
}

void swapRows(float m[MAX_ROWS][MAX_COLS],int row_index1,int row_index2,int r,int c)
{
    int j;

    for (j=0; j<c; j++)
    {
        float temp=m[row_index1][j];
        m[row_index1][j]=m[row_index2][j];
        m[row_index2][j]=temp;
    }
}

void swapInNonZeroRow(float m[MAX_ROWS][MAX_COLS],int row_index,int r,int c)
{
    if (m[row_index][row_index]!=0)
        return;
    else
    {
        int i;
        for (i=row_index+1;i<r;i++)
        {
            if (m[i][row_index]!=0)
            {
                swapRows(m,i,row_index,r,c);
                printf("R%d swapped with R%d:\n",i,row_index);
                printMatrix(m,r,c);
                printf("\n");
            }
        }
    }
}

void subtractRow(float m[MAX_ROWS][MAX_COLS],int row_index_changed,int row_index,int r,int c)
{
    int j;

    for (j=0;j<c;j++)
        m[row_index_changed][j]-=m[row_index][j];
}


