#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//cek operator
int trueOpr(char x){
    if (x=='+' || x=='-')
        return 1;
    else
        return 0;
}

//cek spasi
int cekSpasi(char *str){
    int i;
    for(i=0;str[i]!=0;i++){
        if(str[i]==' '){
            if(isdigit(str[i-1]) && trueOpr(str[i+1])) continue;
            else if(isdigit(str[i + 1]) && trueOpr(str[i - 1]) ) continue;
            else
            {
                printf("Format Salah!");
                return 0;
            }
        }
        if(isdigit(str[i])){
            if( !(str[i + 1] == ' ' || isdigit(str[i + 1])) && !(str[i - 1] == ' ' || isdigit(str[i - 1])) )
            {
                printf("Format Salah!");
                return 0;
            }
        }
        if(trueOpr(str[i])){
            if(str[i + 1] != ' ' || str[i - 1] != ' ')
            {
                printf("Format Salah!");
                return 0;
            }
        }
    }
    if(trueOpr(str[i])){
        printf("Format Salah!");
        return 0;
    }
    return 1;
}

//hapus spasi
char *hapusSpasi(char *str){
    int i=0,j=0;
    while (str[i])
	{
		if (str[i] != ' '){
            str[j++] = str[i];
        }
		i++;
	}
	str[j] = '\0';
	return str;
}

int main(){
    char str[100]; //input string
    int angka [100]; // array integer
    char operator[100]; //array operator

    scanf("%[^\n]",str);

    if(!cekSpasi(str))
        return 0;

    hapusSpasi(str);

//Pendetek angka
    char *ptr = str;
    int i = 0;
    while (*ptr) {
        if ( isdigit(*ptr) ) {
            int val = (int)strtol(ptr, &ptr, 10);
            angka[i] = val;
            i++;
        } else {
            ptr++;
        }
    }

//Pendetek operator
    int j = 1;
    for (int k = 0; k < str[k]; k++){
        if (str[k] == '+' || str[k] == '-'){
            operator[j] = str[k];
            operator[j-1] = '0';
            operator[j+1] = '0';
            j += 2;
        }
    }

//Operasi hitung
    int lendig_k = (strlen(operator)/2) + 1;
    int len_op_k = strlen(operator);

    for (int k = 0; k < strlen(operator); k++){
        if (operator[k] == '+'){
            angka[(k-1)/2] = angka[(k-1)/2] + angka[(k+1)/2];

            for (int l = (k+1)/2; l < lendig_k; l++){
                angka[l] = angka[l+1];
            }
            lendig_k--;

            for (int l = k; l < strlen(operator) - 2 ; l++){
                operator[l] = operator[l+2];
            }

            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                operator[l] = '\0';
            }
            len_op_k = strlen(operator);
            k -= 1;
        }
        if (operator[k] == '-'){
            angka[(k-1)/2] = angka[(k-1)/2] - angka[(k+1)/2];

            for (int l = (k+1)/2; l < lendig_k; l++){
                angka[l] = angka[l+1];
            }
            lendig_k--;

            for (int l = k; l < strlen(operator) - 2 ; l++){
                operator[l] = operator[l+2];
            }

            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                operator[l] = '\0';
            }
            len_op_k = strlen(operator);
            k -= 1;
        }
    }

    printf("Hasil dari operasi tersebut ialah : %d", angka[0]);
}
