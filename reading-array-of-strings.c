#include <stdio.h>

// the input can also be char *arr[]
void read_array_of_strings(char **arr){
    for (int i = 0; i < 3; i++){
        printf("%s and its address:%p\n", arr[i], (void *)arr[i]);
    }
    // above print statements print the following notice the byte difference in addresses
    // first and its address:00007FF7C553506B
    // second and its address:00007FF7C5535071 
    // third and its address:00007FF7C5535078

    // the second's address is 6 more bytes than the first because "first\0" occupies 6 bytes
    // likewise, the third's address is 7 more bytes than the second
}

void read_matrix_of_integers(int nums[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", nums[i][j]);
        }
    }
}

int main(int argc, char *argv[]){

    char *arr[] = { "first", "second", "third" };
    read_array_of_strings(arr);

    int nums[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    read_matrix_of_integers(nums);

    return 0;
}