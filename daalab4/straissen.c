#include <stdio.h>
int main (){
    int A11, A12, A21, A22;
    int B11, B12, B21, B22;
    int C11, C12, C21, C22;
    int p, q, r, s, t, u, v;
    
    printf("enter elements for matrix A:");
    scanf("%d%d%d%d", &A11, &A12, &A21, &A22);
    
     printf("enter elements for matrix B:");
    scanf("%d%d%d%d", &B11, &B12, &B21, &B22);
    
    p=(A11+A22)*(B11+B22);
    q=(A21+A22)*B11;
    r=A11*(B12-B22);
    s=A22*(B21-B11);
    t=(A11+A12)*B22;
    u=(A21-A11)*(B11+B12);
    v=(A12-A22)*(B21+B22);
    
    C11=p+s-t+v;
    C12=r+t;
    C21=q+s;
    C22=p+r-q+u;
    
    printf("%d %d\n", C11, C12);
    printf("%d %d\n", C21, C22);
     
     return 0;
    
}