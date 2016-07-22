
all: test

test: main.cpp GPIO.cpp
	g++ -std=c++11 main.cpp GPIO.cpp -o test

clean:
	rm test
