#include <iostream>
#include <stdio.h>
#define N 10

using namespace std;
void Input(int &row,int &col,int a[N][N]);
void Display(int row, int col,int a[N][N]);
void SortArray(int row, int col,int a[N][N]);
int FindNumber(int row, int col,int a[N][N]);
int main()
{
    int row,col;
    int a[N][N];
    Input(row,col,a);
    SortArray(row,col,a);
    Display(row,col,a);

    int number = FindNumber(row,col,a);
    printf("-----> %d",number);
}

int FindNumber(int row, int col,int a[N][N]){
    int i=0;
    int countMax=0,number,count=0;
    while(i<row*col){
        if (a[i/col][i%col] == a[(i+1)/col][(i+1)%col]){
            count++;
            if(countMax<count){
                countMax =count;
                number = a[i/col][i%col];
            }

        }else{
            count = 0;
        }
        i++;
    }
    return number;
}

void SortArray(int row, int col,int a[N][N]){
    for (int i=0; i<row*col;i++)
        for (int j=0; j<row*col;j++)
            if (a[i/col][i%col] < a[j/col][j%col])
            {
                int tmp = a[i/col][i%col] ;
                a[i/col][i%col] = a[j/col][j%col] ;
                a[j/col][j%col] = tmp ;
            }
}

void Input(int &row,int &col,int a[N][N]){
    printf("Please input\n");
    printf("\tRow: "); scanf("%d",&row);
    printf("\tColumn: ");scanf("%d",&col);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void Display(int row, int col,int a[N][N]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
