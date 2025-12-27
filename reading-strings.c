#include <stdio.h>

// a string can be passed in as (char *str) or (char str[])
void read_string_by_pointer(char *str){
    while((*str) != '\0'){
        printf("%c", *str);
        str += 1;
    }
    printf("\n");
}

void read_string_by_array_iteration(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
    }
}

int main(int argc, char *argv){

    // *str1 is the same as str1[]
    char *str1 = "a - testing - pointer";
    char str2[] = "b - testing - array";
    read_string_by_pointer(str1);
    read_string_by_array_iteration(str2);

    return 0;
}