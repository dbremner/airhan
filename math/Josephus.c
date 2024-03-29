#include <stdio.h> 
#include <stdlib.h> 
#define N 41 

void josephus(int*, int);

int main_call(void) { 
    int alive;
	int man[N] = {0}; 
	int i;
	
	printf("\r\n How many people to save ? \n");     
    scanf("%d", &alive); 
    
   
    josephus(man, alive);

    printf("\n rank"); 

    for(i = 0; i < N; i++) 
        printf("%d ", man[i]); 

	printf("\r\n position: ", alive); 
    for(i = 0; i < N; i++) { 
        printf(man[i] > alive ? "D" : "L");
        printf((i+1) % 5 == 0 ? "  " : "");
    } 
    printf("\n"); 

    return 0; 
} 

void josephus(int* man, int per) {
    int count;
    int pos;
    for(count = 1, pos = -1; count <= N; count++) {
        int i = 0;
        while(i != per) { 
            pos = (pos+1) % N;  
            if(man[pos] == 0) 
                i++; 
        } 
        man[pos] = count; 
    }     
}