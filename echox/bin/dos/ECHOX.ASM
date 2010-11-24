	.186
	ifndef	??version
?debug	macro
	endm
	endif
	?debug	S "..\src\echox.c"
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
	?debug	C E9F859C43A0E2E2E5C7372635C6563686F782E63
	?debug	C E9959BC23A20583A5C444F535C4150505C54433230315C494E434C+
	?debug	C 5544455C737464696F2E68
	?debug	C E9959BC23A21583A5C444F535C4150505C54433230315C494E434C+
	?debug	C 5544455C7374646172672E68
	?debug	C E9949BC23A1D583A5C444F535C4150505C54433230315C494E434C+
	?debug	C 5544455C696F2E68
_BSS	ends
_TEXT	segment	byte public 'CODE'
;	?debug	L 49
_main	proc	near
	enter	266,0
	push	si
	push	di
	cmp	bp,sp
	jb	@38
	cmp	word ptr DGROUP:___brklvl,sp
	jb	@37
@38:
	push	cs
	call	near ptr OVERFLOW@
@37:
;	?debug	L 51
	lea	di,word ptr [bp-264]
;	?debug	L 52
	xor	si,si
;	?debug	L 53
	mov	word ptr [bp-8],si
;	?debug	L 54
	mov	word ptr [bp-6],si
;	?debug	L 55
	mov	word ptr [bp-4],1
;	?debug	L 57
	cmp	word ptr [bp+4],1
	jle	@2
	mov	bx,word ptr [bp+6]
	mov	bx,word ptr [bx+2]
	cmp	byte ptr [bx],45
	jne	@2
	mov	bx,word ptr [bp+6]
	mov	bx,word ptr [bx+2]
	cmp	byte ptr [bx+1],101
	je	@3
	mov	bx,word ptr [bp+6]
	mov	bx,word ptr [bx+2]
	cmp	byte ptr [bx+1],69
	jne	@2
@3:
	mov	bx,word ptr [bp+6]
	mov	bx,word ptr [bx+2]
	cmp	byte ptr [bx+2],0
	jne	@2
;	?debug	L 58
	mov	word ptr [bp-6],1
;	?debug	L 59
	mov	word ptr [bp-4],2
@2:
;	?debug	L 62
	mov	ax,word ptr [bp+4]
	cmp	ax,word ptr [bp-4]
	jne	@7
;	?debug	L 63
	jmp	@5
@9:
;	?debug	L 66
	mov	bx,word ptr [bp-4]
	shl	bx,1
	add	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	inc	word ptr [bx]
	mov	bx,ax
	mov	al,byte ptr [bx]
	mov	bx,si
	mov	byte ptr [bx+di],al
	inc	si
@7:
	mov	bx,word ptr [bp-4]
	shl	bx,1
	add	bx,word ptr [bp+6]
	mov	bx,word ptr [bx]
	cmp	byte ptr [bx],0
	jne	@9
;	?debug	L 67
	mov	ax,word ptr [bp-4]
	inc	ax
	mov	word ptr [bp-8],ax
	jmp	short @13
@12:
;	?debug	L 68
	mov	bx,si
	mov	byte ptr [bx+di],32
	inc	si
;	?debug	L 69
	jmp	short @14
@16:
	mov	bx,word ptr [bp-8]
	shl	bx,1
	add	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	inc	word ptr [bx]
	mov	bx,ax
	mov	al,byte ptr [bx]
	mov	bx,si
	mov	byte ptr [bx+di],al
	inc	si
@14:
	mov	bx,word ptr [bp-8]
	shl	bx,1
	add	bx,word ptr [bp+6]
	mov	bx,word ptr [bx]
	cmp	byte ptr [bx],0
	jne	@16
	inc	word ptr [bp-8]
@13:
	mov	ax,word ptr [bp-8]
	cmp	ax,word ptr [bp+4]
	jl	@12
;	?debug	L 73
	cmp	word ptr [bp-6],0
	jne	@40
	jmp	@17
@40:
;	?debug	L 74
	mov	word ptr [bp-266],si
;	?debug	L 75
	xor	si,si
;	?debug	L 76
	mov	word ptr [bp-8],si
	jmp	@21
@20:
;	?debug	L 77
	mov	bx,word ptr [bp-8]
	add	bx,di
	cmp	byte ptr [bx+1],0
	jne	@41
	jmp	@22
@41:
	mov	bx,word ptr [bp-8]
	cmp	byte ptr [bx+di],92
	je	@42
	jmp	@22
@42:
;	?debug	L 78
	inc	word ptr [bp-8]
	mov	bx,word ptr [bp-8]
	mov	al,byte ptr [bx+di]
	cbw	
	sub	ax,92
	cmp	ax,26
	jbe	@43
	jmp	@33
@43:
	mov	bx,ax
	shl	bx,1
	jmp	word ptr cs:@39[bx]
@39	label	word
	dw	@36
	dw	@33
	dw	@33
	dw	@33
	dw	@33
	dw	@24
	dw	@28
	dw	@33
	dw	@33
	dw	@31
	dw	@25
	dw	@33
	dw	@33
	dw	@33
	dw	@33
	dw	@33
	dw	@33
	dw	@33
	dw	@29
	dw	@33
	dw	@33
	dw	@33
	dw	@27
	dw	@33
	dw	@30
	dw	@33
	dw	@26
@24:
;	?debug	L 79
	mov	bx,si
	mov	byte ptr [bx+di],7
	inc	si
	jmp	short @19
@25:
;	?debug	L 80
	mov	bx,si
	mov	byte ptr [bx+di],12
	inc	si
	jmp	short @19
@26:
;	?debug	L 81
	mov	bx,si
	mov	byte ptr [bx+di],11
	inc	si
	jmp	short @19
@27:
;	?debug	L 82
	mov	bx,si
	mov	byte ptr [bx+di],13
	inc	si
	jmp	short @19
@28:
;	?debug	L 83
	mov	bx,si
	mov	byte ptr [bx+di],8
	inc	si
	jmp	short @19
@29:
;	?debug	L 84
	mov	bx,si
	mov	byte ptr [bx+di],10
	inc	si
	jmp	short @19
@30:
;	?debug	L 85
	mov	bx,si
	mov	byte ptr [bx+di],9
	inc	si
	jmp	short @19
@31:
;	?debug	L 86
	mov	bx,si
	mov	byte ptr [bx+di],27
	inc	si
	jmp	short @19
@33:
;	?debug	L 88
	dec	word ptr [bp-8]
@36:
	mov	bx,si
	mov	byte ptr [bx+di],92
	inc	si
;	?debug	L 90
	jmp	short @19
@22:
;	?debug	L 92
	mov	bx,word ptr [bp-8]
	mov	al,byte ptr [bx+di]
	mov	bx,si
	mov	byte ptr [bx+di],al
	inc	si
@19:
	inc	word ptr [bp-8]
@21:
	mov	ax,word ptr [bp-8]
	cmp	ax,word ptr [bp-266]
	jge	@44
	jmp	@20
@44:
@17:
;	?debug	L 97
	mov	al,byte ptr DGROUP:__streams+20
	cbw	
	mov	word ptr [bp-2],ax
;	?debug	L 98
	or	si,si
	jle	@5
	push	si
	push	di
	push	ax
	call	near ptr _write
	add	sp,6
@5:
;	?debug	L 100
	xor	ax,ax
;	?debug	L 101
	pop	di
	pop	si
	leave	
	ret	
_main	endp
_TEXT	ends
	?debug	C E9
_DATA	segment word public 'DATA'
s@	label	byte
_DATA	ends
	extrn	__streams:word
	extrn	___brklvl:word
	extrn	OVERFLOW@:far
_TEXT	segment	byte public 'CODE'
	extrn	_write:near
_TEXT	ends
	public	_main
	end
