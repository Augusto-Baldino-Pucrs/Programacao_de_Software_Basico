#include <stdio.h>
#include <string.h>

int minha_substring(char str1[], char str2[]){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i = 0; i < len1;i++){
        int j;
        for( j = 0; j < len2; j++){
            if(str1[i+j] != str2[j]){
                break;
            }
        }
        if( j == len2){
            return i;
        }
    }
    return -1;
}

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "world";
    
    int pos = minha_substring(str1, str2);
    
    if (pos != -1) {
        printf("A substring foi encontrada na posicao: %d\n", pos);
    } else {
        printf("A substring nao foi encontrada.\n");
    }
    
    return 0;
}