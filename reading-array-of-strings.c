#include <stdio.h>

// the input can also be char *arr[]
void read_array_of_strings(char **arr){
    for (int i = 0; i < 3; i++){
        printf("%s\n", arr[i]);
    }
}

void read_array_of_integers(int nums[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", nums[i][j]);
        }
    }
}

int main(int argc, char *argv){

    char *arr[] = { "first", "second", "third" };
    read_array_of_strings(arr);

    int nums[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    read_array_of_integers(nums);

    return 0;
}