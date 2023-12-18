#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct jucarii {
	char nume[20];
	char material[20];
	int pret;
}S;

int verificare(char *nume) {
	for (int i = 0; i < strlen(nume); i++)
	{
		if (nume[i] >= 'a' && nume[i] <= 'z')
			return 1;
		else
			return 0;
	}

}

void citier(S*s, int* n) {
	(*n)++;
	int sum=0,i,k=0;
	char numetemp[20];

	do
	{
		printf("nume: "); scanf("%s", (s + *n)->nume);
	} while (verificare((s+*n)->nume)==0);

	printf("material: "); scanf("%s", (s + *n)->material);
	
	strcpy(numetemp, (s + *n)->nume);

	for (int i = 0; i < strlen(numetemp); i++) {
		sum += numetemp[i];
		k++;
	}
	sum = sum / k;
	(s + *n)->pret = sum;
}
void afisare(S* s, int n) {
	for (int i = 0; i <= n; i++)
	{
		printf("%s %s %d\n", (s + i)->nume, (s + i)->material, (s + i)->pret);
	}
}
void sortare(S* s, int n) {
	int i, k;
	S temp;
	do
	{
		k = 0;
		for (i = 0; i < n; i++) {
			if (strcmp((s + i)->nume, (s + i + 1)->nume) > 0) {
				temp = *(s + i);
				*(s + i) = *(s + i+1);
				*(s + i+1)=temp;
				k = 1;
			}
		}
	} while (!k);
}
void stergere_salvare(S* s, int* n) {
	char nume_fisier[20];

	if (*n > 0) {
		strcpy(nume_fisier, (s + 0)->nume);  
		for (int i = 0; i < *n - 1; i++) {
			*(s + i) = *(s + i + 1);
		}
		(*n)--;
		printf("Primul element a fost sters\n");

		FILE* f;
		f = fopen("nume_fisier.txt", "w");

		for (int i = 0; i < *n; i++) {
			fprintf(f, "%s %s %d\n", (s + i)->nume, (s + i)->material, (s + i)->pret);
		}

		fclose(f);
	}
	else {
		printf("Nu exista elemente de sters\n");
	}
}


int main() {
	
	S s[50];
	int n =-1;
	enum MyEnum
	{
		caz0, caz1,caz2,caz3, 
	}opt;
	do
	{
		printf("\n0. iesire\n");
		printf("1. citire\n");
		printf("2. afisare\n");
		printf("3. salvare\n");
		printf("optiunea domneavoastra este: ");

		scanf("%d", &opt);
		switch (opt)
		{
		case caz0: exit(0);
			break;
		case caz1:
			citier(s, &n); 
			break;
		case caz2:
			afisare(s, n);
			break;
		case caz3:
			stergere_salvare(s, &n);
			break;
		default:printf("optiune gresita!!");
			break;
		}
	} while (1);


}