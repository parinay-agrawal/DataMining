#include <bits/stdc++.h>
using namespace std;

struct cluster{
	int nodesct;
	int branchct;
	map<int, int> hashtable;
	vector<cluster *> arr;
};

int main(){
	ifstream infile;
	infile.open("testgraph.tree");

	if(!infile.is_open()){
		perror("file not opened.");
		exit(0);
	}
	string line;
	getline(infile, line);
	getline(infile, line);
	getline(infile, line);
	int levelct=0;
	for(int i=0; i<line.size(); i++){
		if(line[i]==':'){
			levelct++;
		}
	}

	string str, flow, nodename, nodeidx;
	vector<int> v(levelct+1);

	while(true){
		for(int i=0; i<)
		getline(infile, str,' ');
		getline(infile, flow,' ');
		getline(infile, nodename,' ');
		getline(infile, nodeidx);

		cout << str << endl;



		if(infile.eof()){
			break;
		}
	}

	// while(getline(infile, line)){

	// }

	infile.close();	

	return 0;
}