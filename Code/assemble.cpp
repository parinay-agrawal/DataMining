#include <bits/stdc++.h>

using namespace std;

struct paper_data{
	string title;
	string authors;
	int year;
	int index;
	string pbc_venue;
	vector<int> references;	
	string abstract;
};

//typedef struct paper_data Paper;

void display(vector<paper_data> p){
	//cout << "display" <<endl;
	//cout << p.size() <<endl;
	for(int i=0;i<p.size();i++){
		cout << "Index : " <<p[i].index <<endl;
		cout << "Title : " << p[i].title <<endl;
		cout << "Authors : " << p[i].authors <<endl;
		cout << "YOP : " << p[i].year <<endl;
		cout << "Publication Venue : "<<p[i].pbc_venue << endl;
		cout << "References : " <<endl;
		for(int j=0;j<p[i].references.size();j++){
			cout << "\t" << p[i].references[j] <<endl;
			//break;
		}
		cout << "Abstract : " <<endl << p[i].abstract<<endl;
		//break;
	}
}


int main(){
	ifstream infile;
	infile.open("citation-network1/outputacm.txt");
	int n_papers;
	string s ;
	getline(infile,s);
	n_papers = stoi(s);
	cout << n_papers <<endl;
	vector <paper_data> list(n_papers);
	int id = 0;
	int indx =0;

	while(getline(infile,s)){
		if(s.size()<3)continue;
		//cout<< "Input str : " << s <<endl;
		char c = s[1];
		s = s.substr(2);
		if(c== '*' ){
			//cout << s <<endl;
			if(indx ==1){
				indx=0;
				id++;
				//list[id].index = id;
			}
			//cout << "title" <<endl;
			list[id].title = s;
		}
		else if(c=='@'){
			//cout << s <<endl;
			//cout << "authors" <<endl;
			list[id].authors = s;
			//cout << "ID : " <<id<<endl;
			//cout << list[id].authors <<endl;
		}
		else if(c=='t'){
			//cout << s <<endl;
			//cout << "year" <<endl;
			list[id].year = stoi(s);
		}
		else if(c=='c'){
			//cout << s <<endl;
			//cout << "venue" <<endl;
			list[id].pbc_venue = s;
		}
		else if(c=='i'){
			list[id].index = id;
			indx = 1;
		}
		else if(c=='%'){
			//cout << s <<endl;
			//cout << "ref" <<endl;
			list[id].references.push_back(stoi(s));
			continue;
		}
		else if(c=='!'){
			//cout << s <<endl;
			//cout << "abs" <<endl;
			list[id].abstract = s;
		}
		else{
			continue;
		}
		
	}
	//cout << list.size()<<endl;
	display(list);
	//cout << list[0].authors <<endl;
	infile.close();
	return 0;
}
