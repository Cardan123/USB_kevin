org 100

section .text

mov word [temp1] , 5
mov word [temp2] , 7
mov ax, word [temp1]
add ax, word [temp2]
mov word [temp3] , ax 
mov word [temp4] , 8
mov ax, word [temp3]
add ax, word [temp4]
mov word [temp5] , ax 
mov word [temp6] , 9
mov ax, word [temp5]
add ax, word [temp6]
mov word [temp7] , ax 

section .data
temp1 dw 0
temp2 dw 0
temp3 dw 0
temp4 dw 0
temp5 dw 0
temp6 dw 0
temp7 dw 0
