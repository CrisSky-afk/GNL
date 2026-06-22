#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;
	int line_count;

	printf("=== TESTE GET_NEXT_LINE - PARTE OBRIGATÓRIA ===\n\n");

	// Teste 1: Arquivo pequeno
	printf("📝 TESTE 1: Arquivo pequeno (test1.txt)\n");
	printf("----------------------------------------\n");
	fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("❌ Erro ao abrir test1.txt\n");
		return (1);
	}
	
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha %d: [%s]", line_count, line);
		if (line[strlen(line) - 1] != '\n')
			printf(" (sem \\n no final)");
		printf("\n");
		free(line);
		line_count++;
	}
	close(fd);
	printf("✅ Total de linhas lidas: %d\n\n", line_count - 1);

	// Teste 2: Arquivo vazio
	printf("📝 TESTE 2: Arquivo vazio (empty.txt)\n");
	printf("--------------------------------------\n");
	fd = open("empty.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("❌ Erro ao abrir empty.txt\n");
		return (1);
	}
	
	line = get_next_line(fd);
	if (line == NULL)
		printf("✅ Arquivo vazio retornou NULL corretamente\n");
	else
	{
		printf("❌ Arquivo vazio deveria retornar NULL, mas retornou: [%s]\n", line);
		free(line);
	}
	close(fd);
	printf("\n");

	// Teste 3: Linhas muito longas
	printf("📝 TESTE 3: Linhas longas (long_lines.txt)\n");
	printf("-------------------------------------------\n");
	fd = open("long_lines.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("❌ Erro ao abrir long_lines.txt\n");
		return (1);
	}
	
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha %d (%zu chars): [%.50s", line_count, strlen(line), line);
		if (strlen(line) > 50)
			printf("...");
		printf("]\n");
		free(line);
		line_count++;
	}
	close(fd);
	printf("✅ Total de linhas longas lidas: %d\n\n", line_count - 1);

	// Teste 4: Arquivo com uma linha sem \n
	printf("📝 TESTE 4: Linha sem \\n no final (no_newline.txt)\n");
	printf("---------------------------------------------------\n");
	fd = open("no_newline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("❌ Erro ao abrir no_newline.txt\n");
		return (1);
	}
	
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha %d: [%s]", line_count, line);
		if (line[strlen(line) - 1] != '\n')
			printf(" ✅ (sem \\n no final - correto!)");
		printf("\n");
		free(line);
		line_count++;
	}
	close(fd);
	printf("\n");

	// Teste 5: FD inválido
	printf("📝 TESTE 5: File descriptor inválido\n");
	printf("-------------------------------------\n");
	line = get_next_line(-1);
	if (line == NULL)
		printf("✅ FD inválido (-1) retornou NULL corretamente\n");
	else
	{
		printf("❌ FD inválido deveria retornar NULL, mas retornou: [%s]\n", line);
		free(line);
	}

	line = get_next_line(999);
	if (line == NULL)
		printf("✅ FD inválido (999) retornou NULL corretamente\n");
	else
	{
		printf("❌ FD inválido deveria retornar NULL, mas retornou: [%s]\n", line);
		free(line);
	}

	printf("\n🎉 TODOS OS TESTES DA PARTE OBRIGATÓRIA CONCLUÍDOS!\n");
	return (0);
}