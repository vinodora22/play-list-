#include<bits/stdc++.h>

using namespace std;

#define node 7 //Indicate total number of vertex

struct Graph
{
	int V;  
	list<int> *adj;
	
	vector<int> indegree;
};

/*
* For each edge(x,y)
* indegree of 'y' is increased;
*/
void addEdge(Graph *g, int x, int y)
{
    g->adj[x].push_back(y); 
 
    g->indegree[y]++;
}


void initialize(Graph **g, int totalNode)
{
	(*g)->V= totalNode;
	(*g)->adj = new list<int>[totalNode];

	for (int i = 0; i < totalNode; i++)
		(*g)->indegree.push_back(0);

}

/*
*	Gives a path sting traverse till here
*	return string 
*/
string makePath(string str, int index)
{
	char c[3]={0};
	sprintf(c, "%d", index);	
	str.append(c).append("->");
	return str;
}

/*  recursively call PrintNode for all adjacency node
 * 	
 * Print path when no child exist of node[index]  
 */
void PrintNode(Graph *g, int index, string str)
{
	bool *visited = new bool[node];
	
	str = makePath(str, index);
	for (int i = 0; i < node; i++)
		visited[i] = false;
	list<int>:: iterator j;

	bool endNode = true;
	for (j = g->adj[index].begin(); j != g->adj[index].end(); j++)
	{	endNode = false;
		PrintNode(g, *j, str);
	}
	if( endNode == true )	
		cout<<str<<"NULL"<<endl;
}

/*
* Call PrintNode for all node having '0' indegree.

*/
void printPath(Graph *g)
{
	for (int i = 0; i < node; i++)
	{
		if(g->indegree[i] == 0)
			PrintNode(g, i, "");
	}	
}

int main()
{
	struct Graph *g= new Graph;
	initialize(&g, node);

	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 1, 3);
	addEdge(g, 1, 5);
	addEdge(g, 6, 2);
	addEdge(g, 2, 5);

	printPath(g);	
	
	return 0;
}

