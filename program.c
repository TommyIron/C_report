#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int kagistock[4];
int number;
char result[20000];
char alphabet[62] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};

void hukugou(int);


int main(int argc, char *argv[]) {
    int index = 0;
    number = atoi(argv[1]);
    FILE *fp;
    fp = fopen("data.txt", "r");
    int word;
    while ((word = fgetc(fp)) != EOF && index < 19999){
        result[index] = (char)word;
        index++;
    }

    fclose(fp);

    hukugou(number);

    fp = fopen("write.txt", "w");
    for(int i = 0; i < 20000; i++){
        fprintf(fp,"%c",result[i]);
    }
    fclose(fp);
    return 0;
}


void hukugou(int kagi){
    int now;
    for(int i = 3; i >= 0; i--){
        if(i == 3){
            kagistock[i] = kagi / 1000;
            kagi = kagi - kagistock[i] * 1000;
	    printf("%d\n", kagistock[i]);
        }
        if(i == 2){
            kagistock[i] = kagi / 100;
            kagi = kagi - kagistock[i] * 100;
	    printf("%d\n", kagistock[i]);
        }
        if(i == 1){
            kagistock[i] = kagi / 10;
            kagi = kagi - kagistock[i] * 10;
	    printf("%d\n", kagistock[i]);
        }
        if(i == 0){
            kagistock[i] = kagi;
	    printf("%d\n", kagistock[i]);
        }
    }
    int b = 3;
    for (int i = 0; i < 20000; i++) {
        for (int a = 0; a < 62; a++) {
            now = 0;
            if ((result[i] == alphabet[a]) && (b == 3)) {
                now = a - kagistock[3];
                if (now < 0) {
                    now = now + 62;
                }
                result[i] = alphabet[now];
                b = 2;
                break;
            }

            if ((result[i] == alphabet[a]) && (b == 2)) {
                now = a + kagistock[2];
                if (now > 61) {
                    now = now - 62;
                }
                result[i] = alphabet[now];
                b = 1;
                break;
            }

            if ((result[i] == alphabet[a]) && (b == 1)) {
                now = a - (4 * kagistock[1]);
                if (now < 0) {
                    now = now + 62;
                }
                result[i] = alphabet[now];
                b = 0;
                break;
            }

            if ((result[i] == alphabet[a]) && (b == 0)) {
                now = a + (kagistock[i] % 4);
                if (now > 61) {
                    now = now - 62;
                }
                result[i] = alphabet[now];
                b = 3;
                break;
            }

            if ((a == 61) && (result[i] != alphabet[a])) {
                break;
            }

        }
        
    }
}



