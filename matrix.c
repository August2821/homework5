#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int print_matrix(){

}

int addition_matrix(){

}

int subtraction_matrix(){

}

int transpose_matrix(){

}

int multiply_matrix(){

}

void free_matrix(){

}

int main(){
    int row,column,**arr,i,j; 
    scanf("%d %d",&row,&column); //행과 열을 저장할 변수

    arr=(int**)malloc(sizeof(int)*row); //arr[row] 동적 메모리 할당
    for(i=0;i<row;i++){
        arr[i]=(int*)malloc(sizeof(int)*column);
    }

    srand((unsigned)time(NULL));

    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            arr[i][j]=(rand()%50)+1;
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
    
    return 0;
}