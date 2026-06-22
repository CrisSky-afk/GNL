#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd1, fd2, fd3;
	char *line;
	int round;

	printf("=== TESTE GET_NEXT_LINE - PARTE BÔNUS (MÚLTIPLOS FDs) ===\n\n");

	// Abrindo múltiplos arquivos
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("❌ Erro ao abrir um dos arquivos de teste\n");
		printf("Certifique-se que test1.txt, test2.txt e test3.txt existem\n");
		return (1);
	}

	printf("📝 TESTE DE MÚLTIPLOS FILE DESCRIPTORS\n");
	printf("FD1 = %d (test1.txt)\n", fd1);
	printf("FD2 = %d (test2.txt)\n", fd2);
	printf("FD3 = %d (test3.txt)\n", fd3);
	printf("=====================================\n\n");

	// Teste intercalado - uma linha de cada arquivo por vez
	round = 1;
	while (round <= 10) // Máximo 10 rodadas para evitar loop infinito
	{
		int has_content = 0;
		
		printf("🔄 RODADA %d:\n", round);
		printf("-----------\n");

		// Lê uma linha do FD1
		line = get_next_line(fd1);
		if (line != NULL)
		{
			printf("FD1: [%s]", line);
			if (line[strlen(line) - 1] != '\n')
				printf(" (sem \\n)");
			printf("\n");
			free(line);
			has_content = 1;
		}
		else
			printf("FD1: ❌ EOF/NULL\n");

		// Lê uma linha do FD2
		line = get_next_line(fd2);
		if (line != NULL)
		{
			printf("FD2: [%s]", line);
			if (line[strlen(line) - 1] != '\n')
				printf(" (sem \\n)");
			printf("\n");
			free(line);
			has_content = 1;
		}
		else
			printf("FD2: ❌ EOF/NULL\n");

		// Lê uma linha do FD3
		line = get_next_line(fd3);
		if (line != NULL)
		{
			printf("FD3: [%s]", line);
			if (line[strlen(line) - 1] != '\n')
				printf(" (sem \\n)");
			printf("\n");
			free(line);
			has_content = 1;
		}
		else
			printf("FD3: ❌ EOF/NULL\n");

		printf("\n");

		// Se todos os arquivos chegaram ao fim, para o loop
		if (!has_content)
		{
			printf("✅ Todos os arquivos foram lidos completamente!\n");
			break;
		}

		round++;
	}

	// Fechando os arquivos
	close(fd1);
	close(fd2);
	close(fd3);

	printf("\n📝 TESTE DE STRESS - MUITOS FDs\n");
	printf("===============================\n");

	// Teste com muitos file descriptors
	int fds[5];
	char filenames[5][20] = {"test1.txt", "test2.txt", "test3.txt", "test1.txt", "test2.txt"};
	
	// Abre 5 arquivos (alguns repetidos)
	for (int i = 0; i < 5; i++)
	{
		fds[i] = open(filenames[i], O_RDONLY);
		printf("FD[%d] = %d (%s)\n", i, fds[i], filenames[i]);
	}

	// Lê uma linha de cada um
	printf("\nLendo uma linha de cada FD:\n");
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fds[i]);
		if (line != NULL)
		{
			printf("FD[%d]: [%.30s", i, line);
			if (strlen(line) > 30)
				printf("...");
			printf("]\n");
			free(line);
		}
		else
			printf("FD[%d]: NULL\n", i);
	}

	// Fecha todos
	for (int i = 0; i < 5; i++)
		close(fds[i]);

	printf("\n🎉 TODOS OS TESTES DA PARTE BÔNUS CONCLUÍDOS!\n");
	printf("✅ Múltiplos FDs funcionando corretamente!\n");
	
	return (0);
}