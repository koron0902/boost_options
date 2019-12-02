#include <iostream>
#include <boost/program_options.hpp>

int main(const int argc, const char* argv[]){
	using boost::program_options::options_description;
	using boost::program_options::parse_command_line;
	using boost::program_options::value;
	using boost::program_options::variables_map;
	using boost::program_options::store;

	options_description desc("おぷしょん");
	desc.add_options()
			("nyan,n", value<int>()->default_value(3), "にゃ～ん")
			("myon,m", value<std::string>()->default_value("みょみょみょ"), "みょん")
			("help,h", "へるぷ");

	variables_map vm;
	store(parse_command_line(argc, argv, desc), vm);

	if(vm.count("help")){
		std::cout << desc << std::endl;
		return 0;
	}

	auto nyan = vm["nyan"].as<int>();
	auto myon = vm["myon"].as<std::string>();

	std::cout << "nyan: " << nyan << std::endl;
	std::cout << "myon: " << myon << std::endl;


}
