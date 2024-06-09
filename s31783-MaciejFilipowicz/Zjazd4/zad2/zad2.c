#include <stdio.h>

#define BYTES_PER_LINE 16

void printHex(FILE *file) {
    unsigned char buffer[BYTES_PER_LINE];
    size_t bytesRead;
    int offset = 0;

    while ((bytesRead = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
        printf("%08x  ", offset);

        for (int i = 0; i < bytesRead; i++) {
            printf("%02x ", buffer[i]);
            if ((i + 1) % 4 == 0)
                printf(" "); // separate every 4 bytes
        }

        // Pad the output to align the characters properly
        int numSpaces = (BYTES_PER_LINE - bytesRead) * 3 + ((BYTES_PER_LINE - bytesRead) / 4) + 2;
        for (int i = 0; i < numSpaces; i++)
            printf(" ");

        for (int i = 0; i < bytesRead; i++) {
            // Replace non-printable characters with a dot
            if (buffer[i] < 32 || buffer[i] > 126)
                printf(".");
            else
                printf("%c", buffer[i]);
        }

        printf("\n");
        offset += bytesRead;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printHex(file);

    fclose(file);

    return 0;
}
