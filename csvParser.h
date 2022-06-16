// csvParser.h

#ifndef csvParser_h
#define csvParser_h 

std::vector<std::string> split(const std::string &s, char separator)

class csvParser {
	public:
		// read file based on name
		char *fileName[];
		
	void readLine(int line) {
		// output members in the line
	}
	void readFile()
	
		std::ifstream fileRead(fileName);

		std::string text;		
 	
		while (getline (fileRead, text)) {
			std::cout << text;
		}	
		fileRead.close();
	}
};
