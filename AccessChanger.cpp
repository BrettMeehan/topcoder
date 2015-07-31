#include <iostream>
#include <vector>
#include <string>
using namespace std;
class AccessChanger{
    public:
    	vector<string> convert(vector <string> program);
};

vector<string> AccessChanger::convert(vector <string> program){
    for(int i = 0; i < program.size(); i++){
        string line = program[i];
		string processed_line = "";
		bool at_comment = false;
		
		int j = 0;
		while(j < line.length()){
			if(line[j] == '/' && line[j + 1] == '/'){
				at_comment = true;
				processed_line += line.substr(j, string::npos);
				break;
			}
			if(!at_comment){
				if(line[j] == '-' && line[j + 1] == '>'){
					processed_line += '.';
					j += 2;
				}else{
					processed_line += line[j];
					j++;
				}
			}
		}
		program[i] = processed_line;
    }
    return program;
}

int main(){
	AccessChanger a;
	vector<string> program;
	program.push_back("asdf->asdf");
	program.push_back("//comment");
	program.push_back("->->-->//comment");
	program = a.convert(program);
	for(int i = 0; i < program.size(); i++)
		cout<<program[i]<<endl;
	

	return 0;
}
