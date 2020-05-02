#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 6

void merge (int *v, int inicio, int meio, int fim){
	int *temporario, p1, p2, tamanho, i, j, k;
	int fim1=0, fim2=0;
	
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio + 1;
	
	temporario = (int *) malloc(tamanho * sizeof (int));
	if (temporario){
		for (i=0; i<tamanho; i++){
			if (!fim1 && !fim2){
				if (v[p1] < v[p2])	temporario[i] = v[p1++];
				else temporario[i] = v[p2++];
				
				if (p1 > meio) fim1 = 1;
				if (p2 > fim) fim2 = 1;
			}
			else{
				if (!fim1)	temporario[i] = v[p1++];
				else	temporario[i] = v[p2++];
			}
		}
		for (j=0, k = inicio; j<tamanho; j++, k++)	v[k] = temporario[j];
	}
	free (temporario);
}

void MergeSort (int *v, int inicio, int fim){
	int meio;
	if (inicio < fim){
		meio = floor ((inicio + fim) / 2);
		MergeSort (v, inicio, meio);
		MergeSort (v, meio+1, fim);
		merge (v, inicio, meio, fim);
	}
}

// int main(){
//  int v[] = {3,5,67,1,7,4,0,56};
//   int k;
//   MergeSort(v,0, 7);
//   for(k=0;k<8;k++)
//            printf("v[%d]    %d \n",(k),v[k]);
//   return 0;
// }
int main(){

	int i;
	int v[MAX];

	printf("Informe os valores:\n");
	for(int i=0; i<MAX; i++){
		scanf("%d", &v[i]);
	}

	printf("Antes da ordenação:\n");
  for(int i= 0; i < MAX; i++){
  printf("%d  ", v[i]);
}
  printf("\n");
	MergeSort(v, 0, MAX);

  printf("\nValores ordenados\n");
	for(int i = 0; i < MAX; i++){
		printf("%d, ", i, v[i]);
	}

  printf("\n\n");
	return 0;
}