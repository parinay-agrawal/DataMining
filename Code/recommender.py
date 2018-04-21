import pickle

arr = pickle.load(open('clusters_array.pkl','rb'))
nodedict = pickle.load(open('dict.pkl', 'rb'))

paper_id = int(input("Enter paper id: "))
rec_choice = int(input("(0 for expert recommendation)/(1 for classic recommendation): "))


path = [int(i) for i in (nodedict.get(paper_id)[0].split(':'))]
# print(path)
########################################
# Expert, Classic, invalid choice cases

recommendation=[]
no_of_recos = 10

if(rec_choice==0):
	temp=arr
	for i in range(1,len(path)):
		temp = temp[path[i-1]-1]
	recommendation = temp[:no_of_recos]

elif(rec_choice==1):
	temp = arr

	if(len(path)==2):
		recommendation = temp[path[0]][:no_of_recos]
	else:
		for i in range(1,len(path)-1):
			temp = temp[path[i-1]-1]
		recommendation = []
		i=0
		while(len(recommendation)<no_of_recos):
			recommendation += temp[i][:(no_of_recos-len(recommendation))]

else:
	print("Invalid choice.")

print(recommendation)