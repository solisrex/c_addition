#Refs:
#https://stackoverflow.com/questions/12824134/undefined-reference-to-pow-in-c-despite-including-math-h
#http://nuclear.mutantstargoat.com/articles/make/
#

c_adder:
	gcc c_adder.c -o c_adder -lncurses

clean:
	rm -f c_adder.c c_adder