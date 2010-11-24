	ifndef	??version
?debug	macro
	endm
	endif
	?debug	S "echox.c"
_TEXT	segment	byte public 'CODE'
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP,ss:DGROUP
_TEXT	ends
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
	?debug	C E95DBCC43A076563686F782E63
	?debug	C E9949BC23A1D583A5C444F535C4150505C54433230315C494E434C+
	?debug	C 5544455C696F2E68
	?debug	C E9949BC23A20583A5C444F535C4150505C54433230315C494E434C+
	?debug	C 5544455C66636E746C2E68
	?debug	C E93B66C43A086172726370792E68
_BSS	ends
_DATA	segment word public 'DATA'
_DATA	ends
_TEXT	segment	byte public 'CODE'
;	?debug	L 40
_main	proc	near
	push	bp
	mov	bp,sp
	sub	sp,260
	push	si
	push	di
	mov	si,word ptr [bp+6]
;	?debug	L 43
	lea	di,word ptr [bp-260]
@2:
;	?debug	L 48
	mov	word ptr [bp-4],0
;	?debug	L 49
	mov	byte ptr [bp-1],0
	jmp	@3
@5:
;	?debug	L 51
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+1],101
	jne	@6
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+2],0
	jne	@6
;	?debug	L 52
	or	byte ptr [bp-1],1
;	?debug	L 53
	dec	word ptr [bp+4]
;	?debug	L 54
	inc	si
	inc	si
;	?debug	L 55
	jmp	short @7
@6:
;	?debug	L 56
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+1],110
	jne	@8
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+2],0
	jne	@8
;	?debug	L 57
	or	byte ptr [bp-1],2
;	?debug	L 58
	dec	word ptr [bp+4]
;	?debug	L 59
	inc	si
	inc	si
;	?debug	L 60
	jmp	short @9
@8:
;	?debug	L 61
;	?debug	L 62
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+1],101
	jne	@12
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+2],110
	jne	@12
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+3],0
	je	@11
@12:
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+1],110
	jne	@10
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+2],101
	jne	@10
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+3],0
	jne	@10
@11:
;	?debug	L 63
	or	byte ptr [bp-1],3
;	?debug	L 64
	dec	word ptr [bp+4]
;	?debug	L 65
	inc	si
	inc	si
;	?debug	L 66
	jmp	short @13
@10:
;	?debug	L 68
	jmp	short @4
@13:
@9:
@7:
@3:
;	?debug	L 50
	cmp	word ptr [bp+4],1
	jle	@14
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx],45
	jne	@28
	jmp	@5
@28:
@14:
@4:
;	?debug	L 71
	cmp	word ptr [bp+4],1
	jne	@15
	jmp	@16
@15:
;	?debug	L 74
	push	word ptr [si+2]
	lea	ax,word ptr [bp-4]
	push	ax
	push	di
	call	near ptr _arrcpy
	add	sp,6
;	?debug	L 75
	dec	word ptr [bp+4]
	inc	si
	inc	si
;	?debug	L 76
	mov	bx,word ptr [bp-4]
	mov	byte ptr [bx+di],32
	inc	word ptr [bp-4]
	jmp	@17
@19:
;	?debug	L 80
	mov	bx,word ptr [si+2]
	cmp	byte ptr [bx+1],0
	jne	@20
;	?debug	L 81
	mov	bx,word ptr [si+2]
	mov	al,byte ptr [bx]
	cbw	
	cmp	ax,35
	je	@23
	cmp	ax,59
	je	@22
	cmp	ax,94
	je	@24
	jmp	short @25
@22:
;	?debug	L 83
	dec	word ptr [bp-4]
;	?debug	L 84
	push	word ptr [bp-4]
	push	di
	push	word ptr [bp-1]
	call	near ptr _process
	add	sp,6
;	?debug	L 85
	dec	word ptr [bp+4]
;	?debug	L 86
	inc	si
	inc	si
;	?debug	L 87
	jmp	@2
@23:
;	?debug	L 89
	dec	word ptr [bp-4]
;	?debug	L 90
	mov	bx,word ptr [bp-4]
	mov	byte ptr [bx+di],9
	inc	word ptr [bp-4]
;	?debug	L 91
	jmp	short @21
@24:
;	?debug	L 93
	dec	word ptr [bp-4]
;	?debug	L 94
	mov	bx,word ptr [bp-4]
	mov	byte ptr [bx+di],10
	inc	word ptr [bp-4]
;	?debug	L 95
	jmp	short @21
@25:
;	?debug	L 97
	mov	bx,word ptr [si+2]
	mov	al,byte ptr [bx]
	mov	bx,word ptr [bp-4]
	mov	byte ptr [bx+di],al
	inc	word ptr [bp-4]
;	?debug	L 98
	mov	bx,word ptr [bp-4]
	mov	byte ptr [bx+di],32
	inc	word ptr [bp-4]
;	?debug	L 99
	jmp	short @21
@21:
;	?debug	L 101
	jmp	short @26
@20:
;	?debug	L 103
	push	word ptr [si+2]
	lea	ax,word ptr [bp-4]
	push	ax
	push	di
	call	near ptr _arrcpy
	add	sp,6
;	?debug	L 104
	mov	bx,word ptr [bp-4]
	mov	byte ptr [bx+di],32
	inc	word ptr [bp-4]
@26:
;	?debug	L 106
	dec	word ptr [bp+4]
;	?debug	L 107
	inc	si
	inc	si
@17:
;	?debug	L 78
	cmp	word ptr [bp+4],1
	jle	@29
	jmp	@19
@29:
@18:
;	?debug	L 109
	dec	word ptr [bp-4]
;	?debug	L 110
	push	word ptr [bp-4]
	push	di
	push	word ptr [bp-1]
	call	near ptr _process
	add	sp,6
@16:
;	?debug	L 113
	test	byte ptr [bp-1],2
	je	@27
;	?debug	L 114
	mov	ax,1
	push	ax
	mov	ax,offset DGROUP:s@
	push	ax
	mov	al,0
	push	ax
	call	near ptr _process
	add	sp,6
@27:
;	?debug	L 115
	xor	ax,ax
	jmp	short @1
@1:
;	?debug	L 117
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_main	endp
_TEXT	ends
_DATA	segment word public 'DATA'
	dw	0
_DATA	ends
_TEXT	segment	byte public 'CODE'
;	?debug	L 120
_process	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
	push	si
	push	di
	mov	di,word ptr [bp+6]
;	?debug	L 121
	mov	si,word ptr [bp+8]
;	?debug	L 122
	test	byte ptr [bp+4],1
	jne	@51
	jmp	@31
@51:
;	?debug	L 123
	mov	word ptr [bp-2],0
;	?debug	L 124
	xor	si,si
;	?debug	L 125
	mov	word ptr [bp-2],0
	jmp	@35
@34:
;	?debug	L 126
	mov	bx,word ptr [bp-2]
	add	bx,di
	cmp	byte ptr [bx+1],0
	jne	@52
	jmp	@36
@52:
	mov	bx,word ptr [bp-2]
	cmp	byte ptr [bx+di],92
	je	@53
	jmp	@36
@53:
;	?debug	L 127
	inc	word ptr [bp-2]
	mov	bx,word ptr [bp-2]
	mov	al,byte ptr [bx+di]
	cbw	
	sub	ax,92
	cmp	ax,26
	jbe	@54
	jmp	@47
@54:
	mov	bx,ax
	shl	bx,1
	jmp	word ptr cs:@50[bx]
@50	label	word
	dw	@46
	dw	@47
	dw	@47
	dw	@47
	dw	@47
	dw	@38
	dw	@42
	dw	@47
	dw	@47
	dw	@45
	dw	@39
	dw	@47
	dw	@47
	dw	@47
	dw	@47
	dw	@47
	dw	@47
	dw	@47
	dw	@43
	dw	@47
	dw	@47
	dw	@47
	dw	@41
	dw	@47
	dw	@44
	dw	@47
	dw	@40
@38:
;	?debug	L 128
	mov	bx,si
	mov	byte ptr [bx+di],7
	inc	si
	jmp	short @37
@39:
;	?debug	L 129
	mov	bx,si
	mov	byte ptr [bx+di],12
	inc	si
	jmp	short @37
@40:
;	?debug	L 130
	mov	bx,si
	mov	byte ptr [bx+di],11
	inc	si
	jmp	short @37
@41:
;	?debug	L 131
	mov	bx,si
	mov	byte ptr [bx+di],13
	inc	si
	jmp	short @37
@42:
;	?debug	L 132
	mov	bx,si
	mov	byte ptr [bx+di],8
	inc	si
	jmp	short @37
@43:
;	?debug	L 133
	mov	bx,si
	mov	byte ptr [bx+di],10
	inc	si
	jmp	short @37
@44:
;	?debug	L 134
	mov	bx,si
	mov	byte ptr [bx+di],9
	inc	si
	jmp	short @37
@45:
;	?debug	L 135
	mov	bx,si
	mov	byte ptr [bx+di],27
	inc	si
	jmp	short @37
@46:
;	?debug	L 136
	mov	bx,si
	mov	byte ptr [bx+di],92
	inc	si
	jmp	short @37
@47:
;	?debug	L 137
	dec	word ptr [bp-2]
	mov	bx,si
	mov	byte ptr [bx+di],92
	inc	si
	jmp	short @37
@37:
;	?debug	L 139
	jmp	short @48
@36:
;	?debug	L 141
	mov	bx,word ptr [bp-2]
	mov	al,byte ptr [bx+di]
	mov	bx,si
	mov	byte ptr [bx+di],al
	inc	si
@48:
@33:
	inc	word ptr [bp-2]
@35:
	mov	ax,word ptr [bp-2]
	cmp	ax,word ptr [bp+8]
	jge	@55
	jmp	@34
@55:
@32:
@31:
;	?debug	L 162
	cmp	word ptr DGROUP:d@,0
	jne	@49
;	?debug	L 163
	mov	ax,-32766
	push	ax
	mov	ax,offset DGROUP:s@+2
	push	ax
	call	near ptr __open
	pop	cx
	pop	cx
	mov	word ptr DGROUP:d@,ax
@49:
;	?debug	L 169
	push	si
	push	di
	push	word ptr DGROUP:d@
	call	near ptr __write
	add	sp,6
	jmp	short @30
@30:
;	?debug	L 174
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_process	endp
_TEXT	ends
	?debug	C E9
_DATA	segment word public 'DATA'
s@	label	byte
	db	10
	db	0
	db	67
	db	79
	db	78
	db	0
_DATA	ends
_TEXT	segment	byte public 'CODE'
	extrn	_arrcpy:near
	extrn	__open:near
	extrn	__write:near
_TEXT	ends
	public	_process
	public	_main
	end
