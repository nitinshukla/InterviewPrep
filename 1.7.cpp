#include<iostream>
using namespace std;
#define MAX_ROWS 3
int main()
{
    int matrix[MAX_ROWS][MAX_ROWS]={0};
    int matrix2[MAX_ROWS][MAX_ROWS]={0};
    int i,j,k = 0;

     for(i = 0; i < MAX_ROWS; i++)
     {
          for(j = 0; j < MAX_ROWS; j++)
          {            
               matrix[i][j] = k++;
               cout<<matrix[i][j]<<" ";
          }
          cout<<endl;
     }
    for(i = 0; i < MAX_ROWS; i++)
     {
          for(j = 0; j < MAX_ROWS; j++)
          {
               if(matrix[i][j] ==0 && matrix2[i][j] != 1)
               {
                    for(int m=0; m < MAX_ROWS; m++)
                    {
                        matrix[i][m]=0;
                        matrix2[i][m]=1;
                        matrix[m][j]=0;
                        matrix2[m][j]=1;
                    }                   

               }               
          }
     }
     for(i = 0; i < MAX_ROWS; i++)
     {
          for(j = 0; j < MAX_ROWS; j++)
          {
               cout<<matrix[i][j]<<" ";               
          }
          cout<<endl;
     }
}