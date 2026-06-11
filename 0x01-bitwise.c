#include <stdio.h>

int i, bit_a, bit_b;

void _OR_operation();
void _AND_operarion();


int main(){
    _OR_operation();
    _AND_operarion();
    return 0;
}


void _OR_operation(){
    printf("\nBitwise OR Operator\n");
    for(i = 0; i < 4; i++){
        bit_a = (i & 2) / 2;
        bit_b = (i & 1);
        printf("%d || %d = %d\n", bit_a, bit_b, bit_a | bit_b);
    }
}

void _AND_operarion(){
    printf("\nBitwise AND Operator\n");
    for(i = 0; i < 4; i++){
        bit_a = (i & 2) / 2;
        bit_b = (i & 1);
        printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
    }
}


// (i & 2) / 2;
// (i & 1);