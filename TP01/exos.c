\\i worked on this together in class with my friend but struggled a bit coding in cpp and couldnt figure out what the error exactly was:work in progress still
#include<stdio.h>
#include <stdlib.h>


struct node {
    int element;
    struct node * next;
 
};
typedef struct node node;
typedef node * stackList;


struct graph{
    int numNodes;
    int ** head;
};
typedef struct graph graph;

graph createGraph(int n){
    graph G={0,NULL};
    G.numNodes=n;
   
    G.head=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<G.numNodes;i++)
        G.head[i]=(int *)malloc(n*sizeof(int));
    for(int i=0;i<G.numNodes;i++){
        for(int j=0;j<G.numNodes;j++)
            G.head[i][j] = 0;
    }
    return G;
}
void printMatrix(graph G){
    int n=G.numNodes;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ", G.head[i][j]);
        }
        printf("\n");
    }
    return ;
}

void edge(graph *G, int i, int j) {
    if(i==j){
        return ; 
    }
    G->head[i][j] = 1; 
    G->head[j][i]=1; 
    return ;
}

void printGraph(graph G)
{
    for (int i = 0; i <G.numNodes; i++)
    {   
        for(int j=0;j<G.numNodes;j++){
            if(G.head[i][j]==1){
            printf("(%d —> %d)\t", i, j);
                
            }
        }
        printf("\n");
    }
    return ;
}

int isVisited(int i,stackList path){
    stackList temp=path;
    while(temp!=NULL){
        if(temp->element==i){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int main(){
    graph G=createGraph(3);
    edge(&G,0,1);
    edge(&G,0,2);
    printMatrix(G);
    printf("visualization of the graph: \n"); 

    printGraph(G);
    
    return 0;
}
