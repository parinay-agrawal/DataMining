// #include <bits/stdc++.h>
using namespace std;

/* Takes citation graph and returns the normalised ALEF scores for each node */
void ALEF_score(vector <vector <int> > Z, vector <float> &ALEF_norm){

	// Obtaining Z transpose.
	int n = Z.size();
	vector <vector <int> > Zt(n);

	for(int i = 0; i < n; i++){
		for(auto it = Z[i].begin(); it!=Z[i].end(); it++){
			int node = *it;
			Zt[*it].push_back(i);
		}
	}

	// Obtaining w
	vector <long int> w(n);
	for(int i = 0; i < n; i++){
		w[i] = (Z[i].size() + Zt[i].size());
	}

	// Unnormalized ALEF for all nodes.
	vector <float> ALEF_tot(n);
	for(int i = 0; i < n; i++){
		vector <int> v = Zt[i];
		float su = 0.0;
		for(auto it = v.begin(); it!=v.end(); it++){
			int node = *it;
			su += (1.0*w[i]/Z[node].size());
		}
		ALEF_tot[i] = su;
	}

	float tot = accumulate(ALEF_tot.begin(), ALEF_tot.end(), 0.0);
	for(int i = 0; i < n; i++){
		ALEF_norm[i] = (n*ALEF_tot[i]/tot);
	}

}