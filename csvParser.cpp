#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>
#include <vector>
#include <iterator>
#include <ctime>

std::vector<std::string> split(const std::string &s, char separator){
    std::vector<std::string> ret;
    std::string accum;
    for (auto c : s){
        if (c == separator){
            ret.emplace_back(std::move(accum));
            continue;
        }
        accum += c;
    }
    ret.emplace_back(std::move(accum));
    return ret;
}

class csvParser {
	public:
		// read file based on name
		std::string fileName;
		float fileSize;
		std::size_t rows = 0;
		std::vector<std::vector<std::string>> fileData {};
	
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
				// REGEX for splitting string by comma
				std::vector<std::string> result = split(text, ',');
				fileData.push_back(result);
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

	time_t timeStart = time(0);

	csvParser data {"dataTest/charts.csv"};

	data.readFile();

	data.setRows();

	std::cout << data.rows << std::endl;

	// print out two 2d array of csv file

	int dataRows = data.fileData.size();
	int dataColumns = data.fileData[0].size();

	for (int i = 0; i < data.fileData.size(); i++) {
		for (int j = 0; j < data.fileData[i].size(); j++) {
			std::cout << data.fileData[i][j] << "| ";
		}
		std::cout << std::endl;	
	}

	time_t timeEnd = time(0);

	double executionTime = difftime(timeEnd, timeStart);

	std::cout << "Indexed " << dataRows * dataColumns << " items in " << executionTime << " seconds | " << "Rows: " << dataRows << " Columns: " << dataColumns << std::endl;

	return 0;
}
