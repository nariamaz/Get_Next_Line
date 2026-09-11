#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line_bonus.h"

// Função auxiliar para criar arquivos de teste
static void create_test_file(const char *filename, const char *content, size_t size)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Erro ao criar arquivo de teste");
        exit(1);
    }
    if (content && size > 0)
        write(fd, content, size);
    close(fd);
}

// Função auxiliar para ler um arquivo do início ao fim usando 1 FD
static void process_file(const char *filename, const char *description)
{
    int     fd;
    char    *line;
    int     line_count;

    printf("\n===================================================\n");
    printf(" PROCESSANDO: %s\n", description);
    printf("===================================================\n");

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("[ERRO] Nao foi possivel abrir o arquivo: %s\n", filename);
        return;
    }

    line_count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        // Se a linha for muito longa, truncamos apenas na exibição do terminal
        if (strlen(line) > 60)
            printf("Linha %02d (%zu bytes): %.50s... [TRUNCADO PARA EXIBICAO]\n", 
                   line_count, strlen(line), line);
        else
            printf("Linha %02d: %s", line_count, line);

        // Se a linha não terminar em '\n', imprime uma quebra visual para manter o log organizado
        if (line[0] != '\0' && line[strlen(line) - 1] != '\n')
            printf("\n");

        // Libera rigorosamente cada linha retornada
        free(line);
        line_count++;
    }

    printf("--> Fim do arquivo atingido (NULL retornado). Linhas lidas: %d\n", line_count - 1);

    close(fd);
    unlink(filename); // Remove o arquivo temporário do sistema de arquivos
}

int main(void)
{
    // =============================================================
    // ESPECIFICAÇÃO DO ARQUIVO 1: Padrão (linhas curtas, com e sem \n)
    // =============================================================
    const char *f1_name = "test_1_standard.txt";
    const char *f1_content = 
        "Linha 1: Leitura inicial padrao\n"
        "Linha 2: Verificando quebra de linha\n"
        "Linha 3: Ultima linha sem quebra no final";
    create_test_file(f1_name, f1_content, strlen(f1_content));

    // =============================================================
    // ESPECIFICAÇÃO DO ARQUIVO 2: Casos Limite (\n consecutivos e linhas vazias)
    // =============================================================
    const char *f2_name = "test_2_edgecases.txt";
    const char *f2_content = "\n\nA\n\nBC\n";
    create_test_file(f2_name, f2_content, strlen(f2_content));

    // =============================================================
    // ESPECIFICAÇÃO DO ARQUIVO 3: Stress Test (Linha longa de ~5000 chars)
    // =============================================================
    const char *f3_name = "test_3_longline.txt";
    char *long_content = malloc(5000);
    if (!long_content)
        return (1);
    memset(long_content, 'X', 4998);
    long_content[4998] = '\n';
    long_content[4999] = '\0';
    create_test_file(f3_name, long_content, 4999);
    free(long_content); // Libera o buffer usado para gerar o arquivo

    // =============================================================
    // EXECUÇÃO SUCESSIVA DOS TESTES (Seqüencial: 1 -> 2 -> 3)
    // =============================================================
    process_file(f1_name, "Arquivo 1 (Texto Padrao com e sem \\n)");
    process_file(f2_name, "Arquivo 2 (Quebras \\n Consecutivas e Caracteres Isolados)");
    process_file(f3_name, "Arquivo 3 (Stress Test - Linha Extensa de ~5000 bytes)");

    printf("\n===================================================\n");
    printf("   SUCESSO: TODOS OS 3 ARQUIVOS FORAM LIDOS!      \n");
    printf("===================================================\n");

    return (0);
}
