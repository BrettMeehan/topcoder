#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AccessLevel{
    public:
    	string canAccess(vector<int> rights, int minPermission);
};

string AccessLevel::canAccess(vector<int> rights, int minPermission){
    	string accept_deny = "";
    	for(int i = 0; i < rights.size(); i++)
            accept_deny += rights[i] >= minPermission ? 'A' : 'D';
    	return accept_deny;
    }
