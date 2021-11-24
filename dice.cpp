#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <stdexcept>

int roll(int min, int max){		//do not use rand()
	std::mt19937 device;
	std::uniform_int_distribution<int> distribution(min,max);
	return distribution(device);
}

bool addition_overflow(int a, int b){
	return (((b > 0) && (a > (INT_MAX - b))) || ((b < 0) && (a < (INT_MIN - b))));
}

double calculate_average(int min, int max, int sample_size){	
	int sum = 0;												
	for(int i=0;i<sample_size;i++){
		int r = roll(min,max);
		if(addition_overflow(sum, r)){	//check for integer overflow and underflow
			std::cout<<"testing on full sample size would have caused int overflow / underflow, shrinking sample size to "<< i<<"\n";
			sample_size = i;
			break;
		}else{
			sum += roll(min,max);
		}
	}
	return sum / (double) sample_size;
}

int main(int argc, char ** args){
	if(argc != 4){
		std::cout<<"wrong number of arguments\n";
		return -1;
	}
	int min,max,sample_size;
	try{	//check for string to int conversion errors
		min = std::stoi(args[1]);								
		max = std::stoi(args[2]);
		sample_size = std::stoi(args[3]);
	}catch(std::invalid_argument e){
		std::cout<<"all three arguments need to be integers\n";
		return -2;
	}
	
	if(max < min)std::swap(min,max);
	
	std::cout<<calculate_average(min,max,sample_size);
}
