#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necess�rio p/ as fun��es rand() e srand()
#include <time.h>//necess�rio p/ fun��o time()


int main () {
	
	int valores[65],
		l_border_v, r_border_v = 0, 					//bordas valoeres
		l_border_i = 0, r_border_i= 64, 					//bordas index's
		i = 64, j = 0,      							//contadores
		rand_s, 										// valor aleat�rio
		length = sizeof(valores)/sizeof(valores[0]),    //tamanho do vetor
		maior = 0;    
		
	time_t t;
		
//	atribui��o de valores
 	srand((unsigned) time(&t));
 	
 	//valores iniciais
  	valores[l_border_i] = ("%d", rand() % 30);
 	valores[r_border_i] = ("%d", rand() % 30);
// 	printf("valores da posi��o 0: %d\n", valores[0]);
// 	printf("valores da posi��o 64: %d\n", valores[64]);
// 
 	
	//=========valor do meio ==========
	rand_s = ("%d", rand() % 2); //valor aleat�rio
	valores[(i/2)] = ((valores[l_border_i] + valores[r_border_i]) / 2); //media do intervalo 
	
	//atribu��o de valor aleat�rio
	if(rand_s == 1){
		valores[(i/2)+1]++;
	}else{
		valores[(i/2)+1]--;
	}
	//========fim valor dio meio ==========
	
	//inicio caminhamento de quebra do index do meio			
	for(i; i > 1;)
	{
		//bordas
		l_border_i = 0;
		r_border_i = i;
	
		i = (i/2); //posicao do meio
		
		for(j = r_border_i; j < length; j = j + i) // caminhar internamente
		{
			rand_s = ("%d", rand() % 2);  //gera��o aleat�ria
			
			if(!(j == 128)){
				valores[j] = ((valores[l_border_i] + valores[r_border_i]) / 2); //media do intervalo 
				//atribu��o de valor aleat�rio
				if(rand_s == 1){
					valores[j]++;
				}else{
					valores[j]--;
				}
			}
			
			//print debug
//			printf("\nvalor de j: %d\n", j);
//			printf("valor na posi��o %d: %d\n", j, valores[j]);
//			printf("valor de L: %d. valor de R: %d\n", l_border_i, r_border_i);
// 			printf("########################################\n");

			l_border_i += i;
			r_border_i = j;

		} //==================================================
	}

	for(i = 0; i<= length; i++){
		printf("Valor na posi��o %d: %d\n", i, valores[i]);
	}
	

	//======= Pega maior valor ======
	for(i = 0; i <= length; i++){
		if (maior < valores[i]){
			maior = valores[i];
		}
	}
	printf("\nMaior valor: %d (Por favor expanda a janela ===>>)\n", maior);
	for(i = 0; i < 130; i++){
		printf("=");
	}
	
	//gera��o vertical
	printf("\nGrafico:\n");
	for(i = (maior); i >= 0; i--){
		for(j = 0; j< length; j++){
			
			if(valores[j] >= i){
				printf("|%c", (char)254u);
			}else{
				printf("| ");
			}
		}
		printf("|\n");
	}
	printf("\nMaximizar a janela para melhor vizualiacao");
	
	

	//gera��o na horizontal
//	
//	for (i= 0; i <= length; i++)
//	{
//	    
//	    printf("0.%d |", i - 1);
//	    for (j = 0; j < valores[i]; j++)
//	    {
//	        printf("%c", (char)254u);
//	    }
//	    printf("\n");
//	}

	return 0;
}
