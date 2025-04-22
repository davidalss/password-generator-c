#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Conjuntos de caracteres
const char minusc[] = "abcdefghijklmnopqrstuvwxyz";
const char maiusc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char nums[] = "0123456789";
const char especiais[] = "!@#$%&*";

// Função para avaliar nível de segurança
void avaliarSeguranca(int tamanho, int tiposSelecionados) {
    printf("\n🔐 Nível de segurança: ");
    if (tamanho < 6 || tiposSelecionados < 2)
        printf("Fraca\n");
    else if (tamanho < 8)
        printf("Segura\n");
    else if (tamanho < 12)
        printf("Muito segura\n");
    else
        printf("Extremamente segura\n");
}

// Função para gerar a senha
void gerarSenha(int tamanho, int usarMinusc, int usarMaiusc, int usarNums, int usarEspeciais) {
    char conjunto[256] = ""; // Aumente o tamanho para evitar estouro de buffer
    
    if (usarMinusc) strcat(conjunto, minusc);
    if (usarMaiusc) strcat(conjunto, maiusc);
    if (usarNums) strcat(conjunto, nums);
    if (usarEspeciais) strcat(conjunto, especiais);

    int tipos = usarMinusc + usarMaiusc + usarNums + usarEspeciais;
    int len = strlen(conjunto);
    if (len == 0) {
        printf("⚠️ Nenhum tipo de caractere selecionado!\n");
        return;
    }

    char* senha = malloc((tamanho + 1) * sizeof(char));
if (senha == NULL) {
    printf("Erro de alocação de memória!\n");
    return;
}
    for (int i = 0; i < tamanho; i++) {
        senha[i] = conjunto[rand() % len]; // Pode ser substituído por uma função mais segura
    }
    senha[tamanho] = '\0';

    printf("\n🔑 Senha gerada: %s\n", senha);
    avaliarSeguranca(tamanho, tipos);
    free(senha);
    }

// Função principal com menu
int main() {
    srand(time(NULL));
    int tamanho, minusc, maiusc, num, espec;

    printf("=====================================\n");
    printf("🔐  Gerador de Senhas em C - CLI 🔐\n");
    printf("=====================================\n");

    printf("\nInforme o tamanho da senha: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("⚠️ O tamanho da senha deve ser maior que zero!\n");
        return 1;
    }

    printf("Incluir letras minúsculas? (1 = sim / 0 = não): ");
    scanf("%d", &minusc);

    printf("Incluir letras maiúsculas? (1 = sim / 0 = não): ");
    scanf("%d", &maiusc);

    printf("Incluir números? (1 = sim / 0 = não): ");
    scanf("%d", &num);

    printf("Incluir caracteres especiais (!@#$%%&*): (1 = sim / 0 = não): ");
    scanf("%d", &espec);

    if (minusc < 0 || minusc > 1 || maiusc < 0 || maiusc > 1 || num < 0 || num > 1 || espec < 0 || espec > 1) {
        printf("⚠️ As opções devem ser 0 (não) ou 1 (sim)!\n");
        return 1;
    }

    gerarSenha(tamanho, minusc, maiusc, num, espec);

    return 0;
}
