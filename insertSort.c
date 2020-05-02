#include <stdio.h>
#define TAM 10

void InsertSort(int vet[], int N);
void swap (int *vet, int index1, int index2);

int main(int argc, const char * argv[]) {
	int vet [] = {3, 5, 67, 1, 7, 4, 0, 56, 15, 99};


	
	
	int i;
	printf("\n\nAntes da ordenação :  ");
	for(i = 0; i < TAM; i++)
		printf(" %d ", vet[i]);
	
	printf("\n");
	InsertSort(vet, TAM);
	
	printf("\n\nResultado da ordenação:  ");
	for(i = 0; i < TAM; i++)
		printf(" %d ", vet[i]);
        printf("\n\n");
    return 0;
}

// Ordenação por Inserção
void InsertSort (int *vet, int N) {
		// Para cada elemento
	for (int i = 1; i < N; i++) {
        // Mova um ponteiro para trás desse elemento
		// veja se ele precisa ser trocado pelo elemento anterior 
		// e troque conforme necessário
		for (int j = i; j > 0 && vet[j] < vet[j-1]; j--) {
			swap(vet, j, j-1);
		}
	}
}

void swap (int *vet, int index1, int index2) {
	int temporaria = vet [index1];
	vet [index1] = vet [index2];
	vet [index2] = temporaria;
}