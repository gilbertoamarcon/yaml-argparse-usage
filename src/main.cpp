#include <iostream>
#include <fstream>
#include <cxxopts.hpp>
#include <yaml-cpp/yaml.h>

cxxopts::ParseResult argparse(int argc, char** argv){
	try{
		cxxopts::Options options("FR Gen", "FirstResponse Problem Generator.");
		options.add_options()
		("h, help", "Help", cxxopts::value<bool>())
		("i, input_file", "Input file name", cxxopts::value<std::string>()->default_value(""))
		("o, output_file", "Output file name", cxxopts::value<std::string>()->default_value(""));
		cxxopts::ParseResult result = options.parse(argc, argv);
		if(result["help"].as<bool>()){
			std::cout << options.help() << std::endl;
			exit(0);
		}
		return result;
	}catch(const cxxopts::OptionParseException& e){
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

void load_yaml(std::string filename){

	// Loading YAML
	YAML::Node config = YAML::LoadFile(filename);

	for(auto c : config)
		std::cout << c << std::endl;

}

void store_yaml(std::string filename){

	std::list<std::string> names;
	names.push_back("Dude");
	names.push_back("Bude");
	names.push_back("Mude");

	// Generating YAML
	YAML::Emitter yaml;
	yaml << names;

	// Outputting YAML
	std::ofstream output(filename);
	output << yaml.c_str() << std::endl;;
}

int main(int argc, char** argv){

	cxxopts::ParseResult result = argparse(argc, argv);

	load_yaml(result["input_file"].as<std::string>());
	store_yaml(result["output_file"].as<std::string>());

	return 0;


}
