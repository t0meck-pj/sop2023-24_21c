#include <stdio.h>

int main(int argc, char ** argv){
    FILE *file = NULL;
    unsigned char buffer[16];
    size_t bytesRead;
    size_t i;
    long address = 0;

    file = fopen(argv[1], "r");
    
    while ((bytesRead = fread(buffer, 1, 16, file)) > 0) {
        /* print adresu pliku */
        printf("%08lX  ", address);
        
        for (i = 0; i < bytesRead; i++) {
            /* wyprintowanie bajtów w hexie */
            printf("%02X ", buffer[i]);
            if ((i + 1) % 16 == 0){
                for (i = 0; i < 16; i++){
                    /* program printuje tylko znane interpretacje ascii
                       bo gdy drukowal wszystko, niektore linijki
                       nachodzily na siebie.*/
                    if (buffer[i] >= 32 && buffer[i] <= 126){
                        /* zamiana hex na ascii */
                        printf("%c", buffer[i]);
                    }
                    else{
                        printf(".");
                    }
                }
                printf("\n");
            }
            else if ((i + 1) % 4 == 0)
                printf(" ");
        }
        address += bytesRead;
    }

    fclose(file);
    return 0;
}
