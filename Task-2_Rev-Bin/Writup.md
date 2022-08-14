# Programming club secy recruitment task

## Getting Started

Opened the file in ghidra, decompiled it and analyzed the code and the memory. 

![](https://github.com/Akhilstaar/Pclub_Secy_Tasks/blob/main/Task-2_Rev-Bin/images/Screenshot%20from%202022-08-14%2020-27-24.png?raw=true)

Then took the decompiled codes of Process, prepare, verify, Format, CheckRes, CheckPassword and Main.
and pasted them aligned in VS code.



Reading the partially decompiled code tells about the functions being performed. ie. Firstly the variables are defined (including the char arrray of the input password). Then it is calling the checkPassword function with the char array of password in it.

## CheckPassword   Function

The password we entered is returned it this function as `param_1`. Then it is processing the param and location of local_88(`=5`).

I'm moving from end to top.

## CheckRes function

The checkRes function is checking  that the password is equal to &DAT_000120c0 or not.

```c:
    if (0x1d < local_10) {
      return 1;
    }
```

This tells that the length should be greater than 1d(29 in hex) or 30.

Looking for the data stored in `DAT_000120c0` got the 30 characters as

```c:
0x00000cc0, 0x000003a0, 0x00001c00, 0x00000f60, 0x00000140, 0x00000a40, 0x00000180, 0x00000238, 0x00000290, 0x00000680, 0x00000134, 0x000004d0, 0x00000c40, 0x000009c0, 0x000008e0, 0x0000010c, 0x00000130, 0x00000aa0, 0x000000e0, 0x000017c0, 0x00000620, 0x00000062, 0x000002a0, 0x000004b0, 0x00000680, 0x00000270, 0x00000500, 0x00001540, 0x00001480, 0x00000fa0
```

Tried putting them as password but the numbers are quite large & didn't work.

## format function

Moving up to `format` function

It shows that it is left shifting the input array (password) elements by param_2 number of times and then checkRes is comparing them with the predefined array.

So, to get the password we need to right shift the given array by no. of times as defined in param_2.

```c:
param2[] = [0x00000cc0, 0x000003a0, 0x00001c00, 0x00000f60, 0x00000140, 0x00000a40, 0x00000180, 0x00000238, 0x00000290, 0x00000680, 0x00000134, 0x000004d0, 0x00000c40, 0x000009c0, 0x000008e0, 0x0000010c, 0x00000130, 0x00000aa0, 0x000000e0, 0x000017c0, 0x00000620, 0x00000062, 0x000002a0, 0x000004b0, 0x00000680, 0x00000270, 0x00000500, 0x00001540, 0x00001480, 0x00000fa0]
```

writing a simple code should do the work of getting the password now ig.

## CODE

#### In C



```c:

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

```

#### In Python



```python:

shift_arr = [5,3,6,5,2,5,3,3,3,5,2,4,6,5,5,2,2,5,2,6,5,1,3,4,5,3,4,6,6,5]
Pass = [0]*30
arr= [0x00000cc0, 0x000003a0, 0x00001c00, 0x00000f60, 0x00000140, 0x00000a40, 0x00000180, 0x00000238, 0x00000290, 0x00000680, 0x00000134, 0x000004d0, 0x00000c40, 0x000009c0, 0x000008e0, 0x0000010c, 0x00000130, 0x00000aa0, 0x000000e0, 0x000017c0, 0x00000620, 0x00000062, 0x000002a0, 0x000004b0, 0x00000680, 0x00000270, 0x00000500, 0x00001540, 0x00001480, 0x00000fa0]

for i in range(30):
    Pass[i] = arr[i] >> shift_arr[i]
print(''.join([chr(x) for x in Pass]))

```

## Trying the password on the file 

![](https://github.com/Akhilstaar/Pclub_Secy_Tasks/blob/main/Task-2_Rev-Bin/images/Screenshot%20from%202022-08-14%2014-53-10.png)