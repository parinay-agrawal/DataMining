#include <bits/stdc++.h>
#include "ALEF.cpp"

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


void display(vector<paper_data> p){

	for(int i=0;i<p.size();i++){
		cout << "Index : " <<p[i].index <<endl;
		cout << "Title : " << p[i].title <<endl;
		cout << "Authors : " << p[i].authors <<endl;
		cout << "YOP : " << p[i].year <<endl;
		cout << "Publication Venue : "<<p[i].pbc_venue << endl;
		cout << "References : ";
		for(int j=0;j<p[i].references.size();j++){
			cout << "\t" << p[i].references[j];
		}
		cout << endl << "Abstract : " << p[i].abstract << endl << endl;
	}
}

void buildnetwork(int n_papers, vector <paper_data> &paperlist, vector< vector <int> > &Z){
	ifstream infile;
	infile.open("../Data/AMiner-Paper.txt");
	ofstream outfile;
	outfile.open("InputGraph.txt");
	string s;

	int indx;
	int paper_id;

	while(getline(infile,s)){
		if(s.size()<3)continue;
		char c = s[1];
		s = s.substr(3);

		if(c== '*'){
			paperlist[indx].title = s;
		}
		else if(c=='@'){
			paperlist[indx].authors = s;
		}
		else if(c=='t'){
			if(s!=""){
				paperlist[indx].year = stoi(s);
			}
			else{
				paperlist[indx].year = 0;
			}
		}
		else if(c=='c'){
			paperlist[indx].pbc_venue = s;
		}
		else if(c=='i'){
			indx = stoi(s.substr(4))-1;
			paper_id = indx+1;
			paperlist[indx].index = paper_id;
		}
		else if(c=='%'){
			string temp = to_string(paper_id) + " " + s;
			outfile << temp << endl;
			paperlist[indx].references.push_back(stoi(s));
			Z[indx].push_back(stoi(s)-1);
		}
		else if(c=='!'){
			paperlist[indx].abstract = s;
		}
		else{
			continue;
		}
		// if(paper_id%1000==0){
		// 	cout << "Paper id "<< paper_id << endl;
		// }
	}
	infile.close();
	outfile.close();
	return;
}

int main(int argc, char *argv[]){

	if(argc!=2){
		cout << "Error!! Correct format: ./a.out <no_of_papers>" << endl;
		exit(0);
	}
	int n_papers;

	string arg1 = argv[1];
	n_papers = stoi(arg1);
	vector <paper_data> paperlist(n_papers);
	vector< vector <int> > Z(n_papers);

	buildnetwork(n_papers, paperlist, Z);

	vector <float> ALEF_norm(n_papers);
	// ALEF_score(Z, ALEF_norm);
	// for(int i=0; i<n_papers; i++){
	// 	cout << ALEF_norm[i] << endl;
	// }
	// display(paperlist);
	// for(int i=0;i<n_papers;i++){
	// 	for(int j=0; j<Z[i].size();j++){
	// 		cout << Z[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }

	return 0;
}
