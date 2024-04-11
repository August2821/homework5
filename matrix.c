#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int row; //row를 전역변수로 선언
int column; //column을 전역변수로 선언
int **num; //num을 전역변수로 선언, 결과값 저장하는 변수

void print_matrix(int **a);
void addition_matrix(int **a,int **b);
void free_matrix(int **a,int **b);
void subtraction_matrix();
void transpose_matrix();
void multiply_matrix(int **a,int **b);

int main(){
    printf("[----- [김민경] [2023041054] -----]\n\n");

    int **a,**b,i,j;
    printf("row와 column을 입력하세요: ");
    scanf("%d %d",&row,&column);
    printf("\n");

    a=(int**)malloc(sizeof(int)*row);
    b=(int**)malloc(sizeof(int)*row); //arr[row] 동적 메모리 할당
    for(i=0;i<row;i++){
        a[i]=(int*)malloc(sizeof(int)*column);
        b[i]=(int*)malloc(sizeof(int)*column);
    }
    
    num=(int**)malloc(sizeof(int)*row); //arr[row] 동적 메모리 할당
    for(i=0;i<row;i++){
        num[i]=(int*)malloc(sizeof(int)*column);
    }

    //값 할당
    srand((unsigned)time(NULL));
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            a[i][j]=(rand()%50)+1;
            b[i][j]=(rand()%50)+1; 
        }
    }


    printf("행렬 A");
    print_matrix(a);

    printf("행렬 B");
    print_matrix(b);

    printf("addition_matrix");
    addition_matrix(a,b); 
    print_matrix(num);

    printf("subtraction_matrix");
    subtraction_matrix(a,b); 
    print_matrix(num);

    printf("transpose_matrix");
    transpose_matrix(a);
    print_matrix(num);

    printf("multiply_matrix");
    multiply_matrix(a,b);
    print_matrix(num);

    free_matrix(a,b);
    return 0;
}

void print_matrix(int **a){
    int i,j;
    printf("\n===============================\n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("%d\t",a[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void addition_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]+b[i][j];
        }
    }
}

void free_matrix(int **a,int **b){
    int i;
    for(i=0;i<row;i++){
        free(num[i]);
        free(a[i]);
        free(b[i]);
    }
    free(num);
    free(a);
    free(b);
}

void subtraction_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]-b[i][j];
        }
    }
}

void transpose_matrix(int **a){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[j][i];
        }
    }
}

void multiply_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]*b[i][j];
        }
    }
}