#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class AddElectricalWires{
    public:
    	int maxNewWires(vector <string> wires, vector <int> gridConnections);
};

int AddElectricalWires::maxNewWires(vector <string> wires, vector <int> gridConnections){
    int additional_connections = 0;
	int main_grid_connection = -1;
    bool is_connected_to_main_grid = false;
    for(int i = 0; i < gridConnections.size(); i++)
        for(int j = 0; j < wires.size(); j++){
        	if(wires[j][gridConnections[i]] == '1'){
                is_connected_to_main_grid = true;
				main_grid_connection = gridConnections[i];
			}
        }
    for(int i = 0; i < wires.size() - 1; i++){
        for(int j = i + 1; j < wires.size(); j++){
			//nodes must be unconnected, and at least one must be a non-main grid node
			if((wires[i][j] == '0') && (find(gridConnections.begin(), gridConnections.end(), i) == gridConnections.end() || find(gridConnections.begin(), gridConnections.end(), j) == gridConnections.end())){
				//cout<<"unconnected: ("<<i<<", "<<j<<")"<<endl;
				if(is_connected_to_main_grid){//
					if(!((find(gridConnections.begin(), gridConnections.end(), i) != gridConnections.end() && main_grid_connection != i) ||
					     (find(gridConnections.begin(), gridConnections.end(), j) != gridConnections.end() && main_grid_connection != j)))
					   additional_connections++;
				}else{
					if(find(gridConnections.begin(), gridConnections.end(), i) != gridConnections.end()){
						is_connected_to_main_grid = true;
						main_grid_connection = i;
						additional_connections++;
					}else{
						is_connected_to_main_grid = true;
						main_grid_connection = j;
						additional_connections++;
					}
				}	
			}
        }
    }
    return additional_connections;
}


int main (){
	vector<string> v;
	vector<int> i;
	AddElectricalWires a;
	
	i.push_back(0);
	v.push_back("000");
	v.push_back("000");
	v.push_back("000");
	
	cout<<a.maxNewWires(v, i)<<endl;

	return 0;
}
