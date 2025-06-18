#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;

    Edge(int t, int w) : to(t), weight(w) {}
};

struct State {
    int node;
    int distance;

    bool operator>(const State& other) const {
        return distance > other.distance;
    }
};

void dijkstra(int startNode, int endNode, int numNodes, const std::vector<std::vector<Edge> >& adj) {
    std::vector<int> dist(numNodes + 1, INF);
    std::vector<int> prev(numNodes + 1, 0);
    std::priority_queue<State, std::vector<State>, std::greater<State> > pq;

    dist[startNode] = 0;
    pq.push({startNode, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int u = current.node;
        int d = current.distance;

        if (d > dist[u]) {
            continue;
        }

        if (u == endNode) {
            break;
        }

        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }

    if (dist[endNode] == INF) {
        std::cout << "Tidak ada rute dari Node " << startNode << " ke Node " << endNode << std::endl;
    } else {
        std::cout << "Jarak terpendek dari Node " << startNode << " ke Node " << endNode << " adalah: " << dist[endNode] << std::endl;

        std::cout << "Rute terpendek: ";
        std::vector<int> path;
        int currentNode = endNode;
        while (currentNode != 0) {
            path.insert(path.begin(), currentNode);
            currentNode = prev[currentNode];
            if (currentNode == startNode) {
                path.insert(path.begin(), startNode);
                break;
            }
        }
        
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int numNodes = 6;
    std::vector<std::vector<Edge> > adj(numNodes + 1);

    adj[1].push_back({2, 7});
    adj[2].push_back({1, 7});

    adj[1].push_back({6, 14});
    adj[6].push_back({1, 14});

    adj[1].push_back({3, 9});
    adj[3].push_back({1, 9});

    adj[2].push_back({3, 10});
    adj[3].push_back({2, 10});

    adj[2].push_back({4, 15});
    adj[4].push_back({2, 15});

    adj[3].push_back({4, 11});
    adj[4].push_back({3, 11});

    adj[3].push_back({6, 2});
    adj[6].push_back({3, 2});

    adj[6].push_back({5, 9});
    adj[5].push_back({6, 9});

    adj[5].push_back({4, 6});
    adj[4].push_back({5, 6});

    int startNode = 1;
    int endNode = 5;

    dijkstra(startNode, endNode, numNodes, adj);

    return 0;
}
