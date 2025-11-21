#include <stdio.h>

/*
Sistema de pesquisa de satisfação para um serviço de streaming que coleta a
avaliação de 15 usuários. Cada usuário deve classificar o serviço com uma nota de 1 a 5 
(1 - Insatisfeito, 2 - Regular, 3 - Bom, 4 - Muito Bom, 5 - Excelente). 
Usando "for" e "switch case"
*/

int main() {
	int nota, nota1=0, nota2=0, nota3=0, nota4=0, nota5=0, i;
	
	for(i=0; i<15; i++){
		printf("Digite uma nota de 1 a 5\n");
		printf("1 - Insatisfeito\n2 - Regular\n3 - Bom\n4 - Muito Bom\n5 - Excelente\n");
		scanf("%i", &nota);
		switch(nota){
			case 1:
				nota1++;
				break;
			case 2: 
			    nota2++;
			    break;
			case 3:
				nota3++;
			    break;
			case 4:
				nota4++;
			    break;
			case 5: 
			    nota5++;
			    break;
		}
	    
	}
	    printf("Total de notas foi:\n");
		printf("%i notas - Insatisfeito\n", nota1);
		printf("%i notas - Regular\n", nota2);
		printf("%i notas - Bom\n", nota3);
		printf("%i notas - Muito Bom\n", nota4);
		printf("%i notas - Excelente\n", nota5);


}
