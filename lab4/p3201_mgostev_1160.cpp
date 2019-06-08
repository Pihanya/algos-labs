#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    node *root;
    unsigned int number;

    node(unsigned int n) :
            number(n),
            root(this) {};

    node *get_updated_root() {
        while (this->root != this->root->root) {
            this->root = this->root->root;
        }
        return this->root;
    };
};

struct edge {
    node *fst;
    node *snd;

    unsigned int weight;

    edge(node *fst, node *snd, unsigned int weight) :
            fst(fst),
            snd(snd),
            weight(weight) {};
};

vector<node> nodes;
vector<edge> edges, network;

unsigned int N, M, fst, snd, weight, max_distance = 0;

int main() {
    cin >> N >> M;

    nodes.reserve(N);
    edges.reserve(M);
    network.reserve(M);

    for (size_t i = 0; i < N; ++i) {
        nodes.emplace_back(i + 1);
    }

    for (size_t i = 0; i < M; ++i) {
        cin >> fst >> snd >> weight;
        edges.emplace_back(&nodes[fst - 1], &nodes[snd - 1], weight);
    }

    sort(edges.begin(), edges.end(), [](edge a, edge b) { return a.weight < b.weight; });

    for (auto edge : edges) {
        if (edge.fst->get_updated_root() != edge.snd->get_updated_root()) {
            edge.fst->root->root = edge.snd->root->root;
            network.push_back(edge);

            max_distance = max(max_distance, edge.weight);
        }
    }

    cout << max_distance << '\n';
    cout << network.size() << '\n';

    for (auto edge : network) {
        cout << edge.fst->number << " " << edge.snd->number << '\n';
    }

    return 0;
}
