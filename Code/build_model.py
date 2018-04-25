import pandas
import pickle

##########################################################
# Opening the tree file. Only the node and path columns are important, others can be dropped.

df = pandas.read_table("InputTree.tree", delim_whitespace=True)
df.columns = ['path', 'flow', 'name', 'node']
df = df.drop(['flow','name'], axis=1)

############################################################
# To create the dictionary of node and corresponding paths that will help in recommendation.

mydict = df.set_index('node').T.to_dict('list')

with open('dict.pkl','wb') as f:
	pickle.dump(mydict, f, pickle.HIGHEST_PROTOCOL)

##########################################################
# To create the array of clusters.

oriarr =[]
k=0
for index, row in df.iterrows():
	arr = oriarr
	node = row['node']
	path = [int(i) for i in row['path'].split(':')]
	for i in range(1,len(path)):
		if(len(arr) < path[i-1]):
			arr.append([])
		arr = arr[path[i-1]-1]
	arr.append(node)
	k+=1
	if(k%100000==0):
		print(k)

with open('clusters_array.pkl', 'wb') as f:
	pickle.dump(oriarr, f, pickle.HIGHEST_PROTOCOL)
