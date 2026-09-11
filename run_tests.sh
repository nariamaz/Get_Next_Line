#!/bin/bash

# Definição de cores para facilitar a leitura do output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m'

# Arquivos necessários para a compilação
FILES="get_next_line_bonus.c get_next_line_utils_bonus.c main.c get_next_line_bonus.h"

# Variações do BUFFER_SIZE (testando limites de 1 até 10 milhões)
BUFFER_SIZES=(1 2 10 42 9999 10000000)

echo -e "${YELLOW}Iniciando a bateria de testes do Get Next Line...${NC}\n"

for size in "${BUFFER_SIZES[@]}"; do
    echo -e "==============================================================="
    echo -e "${YELLOW}Testando com BUFFER_SIZE = $size ${NC}"
    echo -e "==============================================================="

    # Compilação com as flags exigidas
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=$size $FILES -o gnl_test

    if [ $? -ne 0 ]; then
        echo -e "${RED}>>> ERRO FATAL: Falha na compilação com BUFFER_SIZE=$size <<<${NC}"
        exit 1
    fi

    # Execução com Valgrind. 
    # A flag --error-exitcode=42 forçará o script a capturar vazamentos como erro.
    valgrind --leak-check=full \
             --show-leak-kinds=all \
             --errors-for-leak-kinds=all \
             --error-exitcode=42 \
             ./gnl_test

    EXIT_CODE=$?

    if [ $EXIT_CODE -eq 42 ]; then
        echo -e "\n${RED}>>> FALHA: Memory Leak detectado no BUFFER_SIZE=$size <<<${NC}\n"
        rm -f gnl_test temp_gnl_test.txt
        exit 1
    elif [ $EXIT_CODE -ne 0 ]; then
         echo -e "\n${RED}>>> FALHA: Ocorreu um erro (Segfault ou Lógica) no BUFFER_SIZE=$size <<<${NC}\n"
         rm -f gnl_test temp_gnl_test.txt
         exit 1
    else
        echo -e "\n${GREEN}>>> SUCESSO: Testes e Memória OK para BUFFER_SIZE=$size <<<${NC}\n"
    fi
done

# Limpeza dos binários gerados
rm -f gnl_test temp_gnl_test.txt

echo -e "${GREEN}===============================================================${NC}"
echo -e "${GREEN}   PARABÉNS! Todos os testes e verificações de vazamento passaram! ${NC}"
echo -e "${GREEN}===============================================================${NC}"
