#include <bits/stdc++.h>
using namespace std;

/* Takes citation graph and returns the normalised ALEF scores for each node */
vector <float> ALEF_score(vector <vector <int> > Z){

	int n = Z.size();
	vector <vector <int> > Zt(n);
	for(int i = 0; i < n; i++){
		for(auto it = Z[i].begin(); it!=Z[i].end(); it++){
			int node = *it;
			Zt[*it].push_back(i);
		}
	}
	
	vector <long int> w;
	for(int i = 0; i < n; i++){
		w.push_back(Z[i].size() + Zt[i].size());
	}

	vector <float> ALEF_tot;
	for(int i = 0; i < n; i++){
		vector <int> v = Zt[i];
		float su = 0.0;
		for(auto it = v.begin(); it!=v.end(); it++){
			int node = *it;
			su += 1.0/Z[node].size()*w[i];
		}
		ALEF_tot.push_back(su);
	}

	float tot = accumulate(ALEF_tot.begin(), ALEF_tot.end(), 0.0);
	vector <float> ALEF_norm;
	for(int i = 0; i < n; i++){
		ALEF_norm.push_back(n*ALEF_tot[i]/tot);
	}
	return ALEF_norm;
}