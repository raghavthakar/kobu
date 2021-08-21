// #include <iostream>
// #include<fstream>
// using namespace std;
// void read()
// {
//     ifstream fin;
//     string line;
//     fin.open("robot1_path.csv");
//      while(!fin.eof()){
//                 fin>>line;
//             cout<<line<<" ";
//             }
//     }
// int main()
// {
//     read();
//     return 0;
// }
#include <string>
#include <fstream>
#include <vector>
#include <utility> 
#include <stdexcept> 
#include <sstream> 
#include <iostream>
using namespace std;
std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename){
   
    std::vector<std::pair<std::string, std::vector<int>>> result;
    std::ifstream myFile(filename);
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");
    std::string line, colname;
    int val;
    if(myFile.good())
    {

        std::getline(myFile, line);
        std::stringstream ss(line);
        while(std::getline(ss, colname, ',')){
            result.push_back({colname, std::vector<int> {}});
        }
    }


    while(std::getline(myFile, line))
    {
        std::stringstream ss(line);

        int colIdx = 0;
        
        while(ss >> val){
                       
            result.at(colIdx).second.push_back(val);
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }
    }


    myFile.close();
    return result;
}

int main() {

    std::vector<std::pair<std::string, std::vector<int>>> cols = read_csv("robot1_path.csv");    
    // cout << cols.front();    
    return 0;
}
