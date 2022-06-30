#include <bits/stdc++.h>

/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode* clonedfs(graphNode* node, unordered_map<int, graphNode*> &vis){
    graphNode* newNode = new graphNode(node->data);
    vis.insert({node->data, newNode});

    for(auto n: node->neighbours){
        auto it = vis.find(n->data);

        if(it==vis.end()){
            graphNode* res = clonedfs(n, vis);
            (newNode->neighbours).push_back(res);
        }else{
            (newNode->neighbours).push_back(it->second);
        }
    }
    return newNode;
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    if(node==NULL) return NULL;

    unordered_map<int, graphNode*> vis;

    return clonedfs(node, vis);
}