#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class csvParser {
	public:
		// read file based on name
		std::string fileName;
		float fileSize;
		std::size_t rows = 0;
	
		csvParser(std::string fileNameArg) {
			fileName = fileNameArg;
		}
		
		void readLine(int line) {
		// output members in the line
		}
		void readFile() {
	
			std::ifstream fileRead(fileName);

			std::string text;		
 	
			while (getline(fileRead, text)) {
				std::cout << text << std::endl;
			}
			fileRead.close();
		}
		int setRows() {
			std::ifstream fileRead(fileName);
			char buff[4096];

			while(fileRead.read(buff, sizeof(buff)) || fileRead.gcount()) 	     	 {
				rows += std::count(buff, buff + fileRead.gcount(), '\n');
			}
			return rows;
		}	
};

int main() {
	
	char *twoDArray[2][3] = { {"a","b","c"}, {"d","f","g"}};

	//std::cout << twoDArray[0][1] << std::endl;

	csvParser data {"test"};

	data.readFile();

	data.setRows();

	std::cout << data.rows << std::endl;

	return 0;
}
