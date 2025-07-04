#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
    float nota;
} aluno_t;

int aluno_salva(const char *arquivo, aluno_t *aluno) {
    FILE *fp = fopen(arquivo, "ab");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo para escrita");
        return -1;
    }

    size_t resultado = fwrite(aluno, sizeof(aluno_t), 1, fp);
    fclose(fp);

    return resultado == 1 ? 1 : 0;
}

int aluno_carrega(const char *arquivo, aluno_t alunos[], int len) {
    FILE *fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        return 0;
    }

    int count = 0;
    while (count < len && fread(&alunos[count], sizeof(aluno_t), 1, fp) == 1) {
        count++;
    }

    fclose(fp);
    return count;
}

int main() {
    const char *arquivo = "alunos.dat";

    aluno_t a1 = {"Alice", 20, 8.5f};
    aluno_t a2 = {"Bruno", 22, 7.0f};

    if (aluno_salva(arquivo, &a1))
        printf("Aluno Alice salvo com sucesso.\n");
    if (aluno_salva(arquivo, &a2))
        printf("Aluno Bruno salvo com sucesso.\n");

    aluno_t lidos[10];
    int num_lidos = aluno_carrega(arquivo, lidos, 10);

    printf("\n%d alunos lidos:\n", num_lidos);
    for (int i = 0; i < num_lidos; i++) {
        printf("Nome: %s | Idade: %d | Nota: %.2f\n",
               lidos[i].nome, lidos[i].idade, lidos[i].nota);
    }

    return 0;
}
