all:
	mkdir -p dist
	cc -I -Wall -o dist/password_generator src/main.c 

clean:
	rm -rf dist