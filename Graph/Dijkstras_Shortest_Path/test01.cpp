#include <iostream>
#include <vector>
#include <map>

template <typename T> class Edge;
template <typename T> class Graph;


template <typename T>
class Edge{
	Edge(T s, T d, int w):src(s), dst(d), wgh(w) {}

	friend class Graph<T>;
private:
	T src;
	T dst;
	int wgh;
};

template <typename T>
class Graph{
public:
	Graph(int n): num_nodes(n) {}

	void add(T s, T d, int w){
		Edge<T> e(s, d, w);
		connections.push_back(e);
	}


	void dijkstra(T start){
		std::map<T, int> dist; // distance from start to others
		std::vector<std::pair<T, int>> setds;
		setds.push_back(std::make_pair(start, 0));
		dist[start] = 0;
		while(!setds.empty()){
			// start searching from the smallest
			std::sort(setds.begin(), setds.end(), [&](auto a, auto b){
				return a.second < b.second;		
			});
			std::pair<T, int> temp = setds.front();
			setds.erase(setds.begin());

			int u = temp.first;
			for(int i=0; i < connections.size(); ++i){
				if(connections[i].src == u){
					T v = connections[i].dst;
					int w = connections[i].wgh;
					if(!dist.count(v))
						dist[v] = INT_MAX;
					if(dist[v] > dist[u] + w){
						dist[v] = dist[u] + w;
						setds.push_back(std::make_pair(v, dist[v]));
					}
				}else if(connections[i].dst == u){
					T v = connections[i].src;
					int w = connections[i].wgh;
					if(!dist.count(v))
						dist[v] = INT_MAX;
					if(dist[v] > dist[u] + w){
						dist[v] = dist[u] + w;
						setds.push_back(std::make_pair(v, dist[v]));
					}
				}

			}
		}
		for(auto it = dist.begin(); it != dist.end(); ++it){
			std::cout <<"Node: " << it->first << " Distance: " << it->second << "\n";
		}
	}
	
private:
	std::vector<Edge<T>> connections;
	int num_nodes;
};



int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	Graph<int> g(m);
	int s, d, w;
	for(int i=0; i < n; ++i){
		std::cin >> s >> d >> w;
		g.add(s, d, w);
	}

	g.dijkstra(0);
	
	return 0;
}

