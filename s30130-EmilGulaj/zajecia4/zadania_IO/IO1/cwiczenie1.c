#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int len;
    int *nums;
    int i;
    FILE *file = NULL;
    char filename[50];

    if (argc == 1){
        scanf("%50s", filename);
        file = fopen(filename, "r");
    }
    else if (argc == 2){
        file = fopen(argv[1], "r");
    }
    else{
        printf("Too much arguments.");
        return 0;
    }

    if (file == NULL){
        printf("Cannot open the file.");
        return 0;
    }
    
    fscanf(file, "%d", &len);
    nums = malloc(len * sizeof(int));

    for (i = 0; i < len; i++){
        fscanf(file, "%d", &nums[i]);
    }

    for (i = len - 1; i >= 0 ; i--){
        printf("%d", nums[i]);
    }
    
    free(nums);
    fclose(file);
    return 0;
}