#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int row; //row�� ���������� ����
int column; //column�� ���������� ����
int **num; //num�� ���������� ����, ����� �����ϴ� ����

void print_matrix(); //���� �� ���� print ���ִ� �Լ�
void addition_matrix(); //a+b�� ��� ���ִ� �Լ�
void free_matrix(); //���� �޸� �Ҵ��� ���� ���ִ� �Լ�
void subtraction_matrix();//a-b�� ��� ���ִ� �Լ�
void transpose_matrix();//a�� ��ġ��ķ� �ٲ��ִ� �Լ�
void multiply_matrix();//a*b�� ��� ���ִ� �Լ�

int main(){
    printf("[----- [��ΰ�] [2023041054] -----]\n\n");

    int **a,**b,i,j;
    printf("row�� column�� �Է��ϼ���: ");
    scanf("%d %d",&row,&column); //row�� coulmn �� �Է� �ޱ�
    printf("\n");

    //a, b, num�� row ũ��� �޸� ���� �Ҵ�
    a=(int**)malloc(sizeof(int)*row); 
    b=(int**)malloc(sizeof(int)*row);
    num=(int**)malloc(sizeof(int)*row);

    //a, b, num�� column ũ��� �޸� ���� �Ҵ�
    for(i=0;i<row;i++){
        a[i]=(int*)malloc(sizeof(int)*column);
        b[i]=(int*)malloc(sizeof(int)*column);
        num[i]=(int*)malloc(sizeof(int)*column);
    }
    

    //���ڸ� �������� ������ �ʹ� Ŀ���� 1~50 ������ ���� ����
    srand((unsigned)time(NULL));//���� �ߺ� ���Ÿ� ���� ���
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            a[i][j]=(rand()%50)+1;
            b[i][j]=(rand()%50)+1; 
        }
    }

    //��� A ���
    printf("��� A");
    print_matrix(a);

    //��� B ���
    printf("��� B");
    print_matrix(b);

    //addition_matrix �Լ� ȣ��, ���� �� ���
    printf("addition_matrix");
    addition_matrix(a,b); 
    print_matrix(num);

    //subtraction_matrix �Լ� ȣ��, ���� �� ���
    printf("subtraction_matrix");
    subtraction_matrix(a,b); 
    print_matrix(num);

    //transpose_matrix �Լ� ȣ��, ���� �� ���
    printf("transpose_matrix");
    transpose_matrix(a);
    print_matrix(num);

    //multiply_matrix �Լ� ȣ��, ���� �� ���
    printf("multiply_matrix");
    multiply_matrix(a,b);
    print_matrix(num);

    //�޸� ���� �Ҵ� ���� �Լ� ȣ��
    free_matrix(a,b);
    return 0;
}

//���������ͷ� �ּ� �ޱ�
void print_matrix(int **a){
    int i,j;
    printf("\n===============================\n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("%d\t",a[i][j]); //a[i][j]�� �迭 �������� �����Ͽ� ���
        }printf("\n");
    }
    printf("\n");
}

//���������ͷ� �ּ� �ޱ�
void addition_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]+b[i][j]; //�������� num�� a[i][j]+b[i][j] ���� ����
        }
    }
    //���������� ���� ���� ���� �����Ƿ� return �� ���ʿ�
}

void free_matrix(int **a,int **b){
    int i;

    //num, a, b�� i���� �޸� ����
    for(i=0;i<row;i++){
        free(num[i]);
        free(a[i]);
        free(b[i]);
    }

    //���� �޸� ����
    free(num);
    free(a);
    free(b);
}

void subtraction_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]-b[i][j];//�������� num�� a[i][j]-b[i][j] ���� ����
        }
    }
    //���������� ���� ���� ���� �����Ƿ� return �� ���ʿ�
}

void transpose_matrix(int **a){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[j][i];//�������� num�� a�� ��ġ��� �� ����
        }
    }
    //���������� ���� ���� ���� �����Ƿ� return �� ���ʿ�
}

void multiply_matrix(int **a,int **b){
    int i,j;
    
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           num[i][j]=a[i][j]*b[i][j];//�������� num�� a[i][j]*b[i][j] ���� ����
        }
    }
    //���������� ���� ���� ���� �����Ƿ� return �� ���ʿ�
}