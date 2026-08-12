#include <stdio.h>

int main(){
    int a = 10, b = 20, *pa, *pb;
    pa = &a;
    pb = &b;
    printf("O conteudo de *pa: %d\n", *pa);
    printf("O conteudo de *pb: %d\n", *pb);

    *pa = 500;
    printf("Novo valor de a: %d\n", a);
    b = *pa - b;
    printf("O conteudo de *pb: %d\n", *pb);
    printf("Endereco de b=%p e o valor do ponteiro: %p\n", &b, pb);
    return 0;
}