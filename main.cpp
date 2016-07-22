#include <iostream>
#include <memory.h>
#include "GPIO.h"

using namespace GPIO;

int main_out(int argc, char* argv[]){
	if(argc != 3){
		std::cout << "USAGE : " << argv[0] << " <PIN> <LOW/HIGH>" << std::endl;
		return -1;
	}

	Val val = Val::LOW;
	if(strcmp(argv[2], "HIGH") == 0){
		std::cout << "OUTPUTTING HIGH" << std::endl;
		val = Val::HIGH;
	}else if(strcmp(argv[2], "LOW") == 0){
		std::cout << "OUTPUTTING LOW" << std::endl;
		val = Val::LOW;
	}else{
		std::cout << "INVALID ARGUMENT" << std::endl;
		return -1;
	}

	Pin pin(std::stoi(argv[1]));

	pin.direct(Dir::OUT);

	pin.set(val);

	//std::cout << pin.get() << std::endl;
	//waiting...
	char garbage;
	std::cin >> garbage;
}

int main_in(int argc, char* argv[]){
	if(argc != 2){
		std::cout << "USAGE : " << argv[0] << " <PIN>" << std::endl;
		return -1;
	}

	Pin pin(std::stoi(argv[1]));
	pin.direct(Dir::IN);

	std::cout << "VALUE : " << pin.get() << std::endl;
}

int main(int argc, char* argv[]){
	return main_in(argc,argv);
}
