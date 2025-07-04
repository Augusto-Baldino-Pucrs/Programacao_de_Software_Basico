void multiplicar(int* x){
    *x = *x * *x;
}

int main() {
    int t = 10;;
    multiplicar(&t);
    printf("%d\n",t);
}