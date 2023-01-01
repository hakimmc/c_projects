#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include <conio.h>

void main(void)
{
    int i;
    long n;
    FILE *wavFile;
    char* filename;
	FILE *dosya = fopen("xxx.xlsx", "w");
    fprintf(dosya, "unsigned char mehter_wavfile[] = {");
    printf("The data output \n\n\r");
    char* address;
    //scanf("%s",&address);
    wavFile = fopen("bomb.wav","rb");
    int counter=0;
    while(feof(wavFile)==0)
    {
        i = getw(wavFile);

        if(ferror(wavFile)!=0)
        {
            printf("\n an error has occured");
            n = ftell(wavFile);
            printf("\nThe value of n is %ld",n);
            fclose(dosya);
            getch();
        }   
    i |= 0x00;
    printf(" 0x%02x,",(unsigned int)(i & 0xFF));
    fprintf(dosya, " 0x%02x,",(unsigned int)(i & 0xFF));
    counter++;
    if(counter%150==0){
    	counter=0;
    	printf("\n");
    	fprintf(dosya, "\n");
	}
    }
	fprintf(dosya, "}");
    n = ftell(wavFile);
    printf("\n\The value of n is %ld",n);
    fclose(wavFile);
    printf("\n\nEnd of File");
    fclose(dosya);
    getch();
} 
