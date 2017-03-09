#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int N = 10;
bool visited[N];

struct Graph {
    int edges[N][N];
    int num_v;
    int num_e;
    Graph(const int & nv, const int & ne): num_v(nv), num_e(ne) {}
};

void InitGraph(Graph &g) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            g.edges[i][j] = 0;
        }
        visited[i] = false;
    }

/*
    int src = 0, dst = 0;
    for (int i = 0; i < g.num_e; ++i) {
        cout << "Input the " << i << " edge: (from <= 9) (to <= 9)" << endl;
        cin >> src;
        cin >> dst;
        if (src < 0 || src >= N || dst < 0 || dst >= N) {
            cout << "Error input, re-input." << endl;
            continue;
        }
        g.edges[src][dst] = 1;
        g.edges[dst][src] = 1;
    }
*/
    return;
}

// Visit vertex v of graph g -- recursion version.
void DFS(Graph & g, int v) {
    if (v < 0 || v >= N) {
        return;
    }
    cout << v << " ";
    visited[v] = true;

    for (int i = 0; i < g.num_v; ++i) {
        if (g.edges[v][i] != 0 && visited[i] == false) {
            DFS(g, i);
        }
    }
}

// Visit vertex v of graph g -- non-recursion version.
void DFS_2(Graph & g, int v) {
    if (v < 0 || v >= N) {
        return;
    }

    cout << v << " ";
    visited[v] = true;

    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int i, j;
        i = s.top();
        for (j = 0; j < g.num_v; ++j) {
            if (g.edges[i][j] != 0 && visited[j] == false) {
                cout << j << " ";
                visited[j] = true;
                s.push(j);
                break;    // If we found a unvisited vertex, jump out of the for loop.
            }
        }
        if (j == g.num_v) {  // If all the adjacent vertices have been visited, pop vertex i.
            s.pop();
        }
    }
    return;
}

// Visit vertex v of graph g -- non-recursion version.
void BFS(Graph & g, int v) {
    if (v < 0 || v >= N) {
        return;
    }

    cout << v << " ";
    visited[v] = true;

    queue<int> q;
    q.push(v);

    while(!q.empty()) {
        int i, j;
        i = q.front();
        q.pop();
        for (j = 0; j < g.num_v; ++j) {
            if (g.edges[i][j] != 0 && visited[j] == false) {
                cout << j << " ";
                visited[j] = true;
                q.push(j);
            }
        }
    }
    return;
}





int main() {
    Graph g(6, 6);
    InitGraph(g);
    g.edges[0][1] = g.edges[1][0] = 1;
    g.edges[0][2] = g.edges[2][0] = 1;
    g.edges[0][3] = g.edges[3][0] = 1;
    g.edges[1][4] = g.edges[4][1] = 1;
    g.edges[1][5] = g.edges[5][1] = 1;
    g.edges[2][5] = g.edges[5][2] = 1;

    cout << "DFS recursion version: ";
    DFS(g, 0);
    cout << endl;

    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    cout << "DFS non-recursion version: ";
    DFS_2(g, 0);
    cout << endl;

    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    cout << "BFS non-recursion version: ";
    BFS(g, 0);
    cout << endl;

    return 0;
}



