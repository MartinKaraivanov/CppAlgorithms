#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

int numberOfVertices;
int numberOfEdges;

struct Edge{
    int toVertex;
    int flow;
    int capacity;
    int rev;
    int startCapacity;
};

vector<Edge> adj[110];

int level[110];

int start[110];

bool bfs(int from, int to){
    for(int i = 1; i <= numberOfVertices; i++){
        level[i] = -1;
    }

    level[from] = 0;

    queue<int> q;

    q.push(from);

    while(q.empty() == false){
        int inFront = q.front();
        q.pop();
        //cout<<inFront<<endl;

        for(unsigned int i = 0; i < adj[inFront].size(); i++){
            Edge next = adj[inFront][i];

            //cout<<"the next one is "<<next.toVertex<<" and it's level is "<<level[next.toVertex]<<endl;

            if(level[next.toVertex] < 0 && next.flow < next.capacity){
                level[next.toVertex] = level[inFront] + 1;

                //cout<<"we are pushing "<<next.toVertex<<" in the queue "<<endl;
                q.push(next.toVertex);
            }
        }
    }

    //cout<<"we return_____________________________________________"<<endl;
    return level[to] >= 0;
}

int sendFlow(int currentV, int flow, int sink){
    //cout<<currentV<<endl;
    if(currentV == sink){
        return flow;
    }



    for( ; start[currentV] < (signed int)adj[currentV].size(); start[currentV]++){
        Edge &next = adj[currentV][start[currentV]];

        if(level[next.toVertex] == level[currentV] + 1 && next.flow < next.capacity){
            int currentFlow = min(flow, next.capacity - next.flow);

            int temporaryFlow = sendFlow(next.toVertex, currentFlow, sink);

            if(temporaryFlow > 0){
                next.flow += temporaryFlow;

                adj[next.toVertex][next.rev].flow -= temporaryFlow;

                return temporaryFlow;
            }
        }
    }

    return 0;
}

int Dinic(int from, int to){
    if(from == to){
        return -1;
    }

    int total = 0;

    while(bfs(from, to) == true){
        for(int i = 0; i <= numberOfVertices; i++){
            start[i] = 0;
        }

        while(true){
            int currentFlow = sendFlow(from, 100000000, to);

            //cout<<"Now the current flow is "<<currentFlow<<endl;

            if(currentFlow > 0){
                total += currentFlow;
            }else{
                break;
            }
        }
    }

    return total;
}

vector<int> edges[111];

void buildAdj(){
    for(int i = 1; i <= numberOfVertices; i++){
        for(int j = 0; j < (int)adj[i].size(); j++){
            adj[i][j].capacity = adj[i][j].startCapacity;
            adj[i][j].flow = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>numberOfVertices>>numberOfEdges;

    for(int i = 0; i < numberOfEdges; i++){
        int fromEdge;
        int toEdge;
        cin>>fromEdge>>toEdge;

        adj[fromEdge].push_back({toEdge, 0, 1, (signed int)adj[toEdge].size(), 1});
        adj[toEdge].push_back({fromEdge, 0, 0, (signed int)adj[fromEdge].size(), 0});

        adj[toEdge].push_back({fromEdge, 0, 1, (signed int)adj[fromEdge].size(), 1});
        adj[fromEdge].push_back({toEdge, 0, 0, (signed int)adj[toEdge].size(), 0});
    }

    int minFlow = 100000000;

    for(int i = 2; i <= numberOfVertices; i++){
        buildAdj();

        int flowHere = Dinic(1, i);
        //cout<<flowHere<<endl;
        if(flowHere > 0){
            minFlow = min(minFlow, flowHere);
        }
    }


    cout<<minFlow<<endl;

    return 0;
}
