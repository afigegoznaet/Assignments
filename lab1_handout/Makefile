fp:	fp_program.o fp_functs.o lex.yy.o
	gcc -o fp fp_program.o fp_functs.o lex.yy.o -lfl -lm

fp_functs.o:	fp_functs.c
	gcc -c fp_functs.c	

fp_program.o:	fp_program.c
	gcc -c fp_program.c	

lex.yy.o:	lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:	fp.l
	flex fp.l

clean:
	rm -rf fp lex.yy.c *.o
