/* Esercizio 2: Temperatura, array e funzioni
 * A) Chiedere all'utente il numero di giorni N (1<=N<=31) 
 * B) Dichiarazione di un array di float di dimensione N
 * C) Leggere da tastiera le temeperature dei N giorni
 * D) Implementare le seguenti funzioni: media, massimo, minimo, maggiori della media
 * E) Stampare media delle temperature, massima e minma e quanti giorni con temperatura
 *	  maggiore della media
 * 24/11/2025
 */
 
 #include <stdio.h>
  
#define N 40

float calcola_media (float v[], int n){
		float somma = 0, average, den;
		int i;
		for (i=0;i<n; i++){
			somma += v[i];
		}
		den = (float) n;
		return somma/den;
}

float trova_massimo(float v[], int n){
		float max;
		int i;
		max = v[0];
		for(i=1; i<n; i++){
			if (v[i]>max){
				max = v[i]; //new max
			}	
		}
		return max;
}
float trova_minimo(float v[], int n){
		float min;
		int i;
		min = v[0];
		for(i=1; i<n; i++){
			if (v[i]<min){
				min = v[i]; //new max
			}	
		}
		return min;
}
int conta_maggiori_di_media(float v[], int n){
	float media = calcola_media (v, n);
	int count = 0, i;
	for (i=0;i<n;i++){
		if (v[i]>media) count++;
	}
	return count;
}

int main (){
	
	//Variabili
	int i , n_of_days;
	float average_temp;
	
		
	//Chiede all'utente il numero di giorni n_of_days compreso tra 1 e 31
	printf("--- Analisi temperature giornaliere ---\n");
	do {
		printf("Di quanti giorni analizzare [1-31]: ");
		scanf ("%d", &n_of_days);
		if (n_of_days<1 || n_of_days>31){
				printf("Errore: inserisci un valore nell'intervallo [1-31]\n");
			}
	}while (n_of_days<1 || n_of_days>31);
	
	//Dichiarazione di un array di float di dimensione n_of_days
	float temp [n_of_days];

	//Leggere da tastiera le temeperature dei giorni 
	for (i=0; i<n_of_days; i++){
		printf("Temperatura |Giorno %d|: ", i+1);
		scanf("%f", &temp[i]);
	}
	
	//Stampa temperatura media
	printf("--------------------\n");
	printf("Temperatura Media:\t\t%.2f\n", calcola_media(temp, n_of_days));
	
	//Stampa temperatura massima e minima
	printf("Temperatura Massima:\t\t%.2f\nTemperatura Minima:\t\t%.2f\n", trova_massimo(temp, n_of_days), trova_minimo(temp, n_of_days));
	
	//Stampa giorni con temperatura superiore alla media
   	printf("Giorni con T > T media:\t\t%d", conta_maggiori_di_media(temp, n_of_days));
	   
	return 0;
   }
