#include <stdio.h>

int main(){
    int shift_arr[] = {5,3,6,5,2,5,3,3,3,5,2,4,6,5,5,2,2,5,2,6,5,1,3,4,5,3,4,6,6,5};
    char pass[30];
    int i=0;
    
    while(i<30){
        pass[i++]='0';
    }
    
    unsigned int arr[30]= {0x00000cc0, 0x000003a0, 0x00001c00, 0x00000f60, 0x00000140, 0x00000a40, 0x00000180, 0x00000238, 0x00000290, 0x00000680, 0x00000134, 0x000004d0, 0x00000c40, 0x000009c0, 0x000008e0, 0x0000010c, 0x00000130, 0x00000aa0, 0x000000e0, 0x000017c0, 0x00000620, 0x00000062, 0x000002a0, 0x000004b0, 0x00000680, 0x00000270, 0x00000500, 0x00001540, 0x00001480, 0x00000fa0};
    i=0;
    while(i<30)
    {
        pass[i]= arr[i] >> shift_arr[i];
        i++;
    }
    
    for (i=0; 30>i; i++){
        printf("%c",pass[i]);
    }
    return 0;
}