// csvParser.h

#ifndef csvParser_h
#define csvParser_h 

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
