encrypt:
	g++ -o encrypt encrypt.cpp

decipher:
	g++ -o decipher decipher.cpp

clean:
	rm -f encrypt decipher