# DataMining

## Create the hierarchically clustered graph
### In code folder:
g++ -std=c++11 assemble.cpp -o assemble

./assemble

### Then in InfoMap folder
./Infomap --tree -t --undirdir [path-to-InputGraph.txt] [path-where-output-tree-is-to-be-stored]

cat [path-to-InputGraph.tree] | tail -n +3 > [path-where-output-tree-is-to-be-stored]/InputTree.tree

### Run recomender
python build_model.py

python recommender.py

