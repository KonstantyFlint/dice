#include <iostream>
#include <cstdlib>
#include <string>

int roll(int min, int max){
	return rand() % (max - min + 1) + min;
}

double calculate_average(int min, int max, int sample_size){
	int sum = 0;
	for(int i=0;i<sample_size;i++){
		sum += roll(min,max);
	}
	return sum / (float) sample_size;
}

int main(int argc, char ** args){
	if(argc != 4){
		std::cout<<"wrong number of arguments\n";
		return -1;
	}
	int min = std::stoi(args[1]);
	int max = std::stoi(args[2]);
	int sample_size = std::stoi(args[3]);
	std::cout<<calculate_average(min,max,sample_size);
}
