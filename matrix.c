#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int row; //row를 전역변수로 선언
int column; //column을 전역변수로 선언
int **num; //num을 전역변수로 선언, 결과값 저장하는 변수

void print_matrix(); //연산 된 값을 print 해주는 함수
void addition_matrix(); //a+b를 계산 해주는 함수
void free_matrix(); //동적 메모리 할당을 해제 해주는 함수
void subtraction_matrix();//a-b를 계산 해주는 함수
void transpose_matrix();//a를 전치행렬로 바꿔주는 함수
void multiply_matrix();//a*b를 계산 해주는 함수

int main(){
    printf("[----- [김민경] [2023041054] -----]\n\n");

    int **a,**b,i,j;
    printf("row와 column을 입력하세요: ");
    scanf("%d %d",&row,&column); //row와 coulmn 값 입력 받기
    printf("\n");

    //a, b, num을 row 크기로 메모리 동적 할당
    a=(int**)malloc(sizeof(int)*row); 
    b=(int**)malloc(sizeof(int)*row);
    num=(int**)malloc(sizeof(int)*row);

    //a, b, num을 column 크기로 메모리 동적 할당
    for(i=0;i<row;i++){
        a[i]=(int*)malloc(sizeof(int)*column);
        b[i]=(int*)malloc(sizeof(int)*column);
        num[i]=(int*)malloc(sizeof(int)*column);
    }
    

    //숫자를 제한하지 않으면 너무 커져서 1~50 사이의 난수 생성
    srand((unsigned)time(NULL));//난수 중복 제거를 위해 사용
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            a[i][j]=(rand()%50)+1;
            b[i][j]=(rand()%50)+1; 
        }
    }

    //행렬 A 출력
    printf("행렬 A");
    print_matrix(a);

    //행렬 B 출력
    printf("행렬 B");
    print_matrix(b);

    //addition_matrix 함수 호출, 연산 후 출력
    printf("addition_matrix");
    addition_matrix(a,b); 
    print_matrix(num);

    //subtraction_matrix 함수 호출, 연산 후 출력
    printf("subtraction_matrix");
    subtraction_matrix(a,b); 
    print_matrix(num);

    //transpose_matrix 함수 호출, 연산 후 출력
    printf("transpose_matrix");
    transpose_matrix(a);
    print_matrix(num);

    //multiply_matrix 함수 호출, 연산 후 출력
    printf("multiply_matrix");
    multiply_matrix(a,b);
    print_matrix(num);

    //메모리 동적 할당 해제 함수 호출
    free_matrix(a,b);
    return 0;
}

//이중포인터로 주소 받기
void print_matrix(int **a){
    int i,j;
    printf("\n===============================\n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("%d\t",a[i][j]); //a[i][j]로 배열 형식으로 접근하여 출력
        }printf("\n");
    }
    printf("\n");
}

//이중포인터로 주소 받기
void addition_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]+b[i][j]; //전역변수 num에 a[i][j]+b[i][j] 값을 저장
        }
    }
    //전역변수에 연산 값을 저장 했으므로 return 값 불필요
}

void free_matrix(int **a,int **b){
    int i;

    //num, a, b의 i행의 메모리 해제
    for(i=0;i<row;i++){
        free(num[i]);
        free(a[i]);
        free(b[i]);
    }

    //남은 메모리 해제
    free(num);
    free(a);
    free(b);
}

void subtraction_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]-b[i][j];//전역변수 num에 a[i][j]-b[i][j] 값을 저장
        }
    }
    //전역변수에 연산 값을 저장 했으므로 return 값 불필요
}

void transpose_matrix(int **a){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[j][i];//전역변수 num에 a의 전치행렬 값 저장
        }
    }
    //전역변수에 연산 값을 저장 했으므로 return 값 불필요
}

void multiply_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]*b[i][j];//전역변수 num에 a[i][j]*b[i][j] 값을 저장
        }
    }
    //전역변수에 연산 값을 저장 했으므로 return 값 불필요
}