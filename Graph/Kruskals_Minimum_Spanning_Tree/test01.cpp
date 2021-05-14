#include <iostream>
#include <vector>
#include <algorithm>

struct Edge{
	int src;
	int dst;
	int weight;
};



class Graph{
public:
	Graph(int _n)
		:n(_n)
	{}

	void add(int src, int dst, int weight){
		Edge e;
		e.src = src;
		e.dst = dst;
		e.weight = weight;
		connections.push_back(e);
	}

	std::vector<Edge> kruskalMST(){
		std::vector<int> group(n);
		std::vector<Edge> mst;
		int size = 0;
		std::sort(connections.begin(), connections.end(), [](Edge &a, Edge &b){
			return a.weight < b.weight;
		});
		
		for(int i = 0; i < connections.size(); ++i){
			if(group[connections[i].src]==0 && group[connections[i].dst]==0)
			{
				size++;
				group[connections[i].src]=size;
				group[connections[i].dst]=size;
				mst.push_back(connections[i]);
			}
			else if(group[connections[i].src]==0 && group[connections[i].dst]!=0 )
			{
				group[connections[i].src]=group[connections[i].dst];
				mst.push_back(connections[i]);
			}
			else if(group[connections[i].src]!=0 && group[connections[i].dst]==0 )
			{
				group[connections[i].dst]=group[connections[i].src];
				mst.push_back(connections[i]);

			}
			else if(group[connections[i].src]!=group[connections[i].dst])
			{
				// store original value as vector group will change
				int g_src = group[connections[i].src];
				int g_dst = group[connections[i].dst];
				for(int j = 0; j < n; ++j){
					if(group[j]==g_src){
						group[j]=g_dst;
					}
				}
				mst.push_back(connections[i]);
			}
			// when group[connections[i].src]!=group[connections[i].dst], do not add it to mst list

		}
		return mst;
	}

	
private:
	std::vector<Edge> connections;
	int n;
};


int main(int argc, char *argv[]){
	int n, nodes;
	std::cin >> n >> nodes;
	Graph g(nodes);
	for(int i = 0; i < n; ++i){
		int src, dst, weight;
		std::cin >> weight >> src >> dst;
		g.add(src, dst, weight);
	}
	std::vector<Edge> mst= g.kruskalMST();
	std::cout << "MST is:\n";
	for(int i = 0; i < mst.size(); ++i){
		std::cout << mst[i].weight<< " "<<  mst[i].src<<" " <<mst[i].dst << "\n";
	}

	return 0;
}
