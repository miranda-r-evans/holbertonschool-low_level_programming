segment .text
	global_start

_start:
	mov edx,len
	mov ecx,msg
	mov ebx,1
	mov eax,4
	int 0x80

	mov eax,1
	int 0x80

segment .data
	msg	db 'Hello, Holberton\n',0xa
	len	equ	$ - msg
