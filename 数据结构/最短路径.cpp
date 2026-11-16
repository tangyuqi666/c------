//djikstra
#include<stdio.h>
#include<stdlib.h>
typedef int VertexType;
typedef int EdgeType;
#define MaxSize 100
#define MaxEdge 200
#define MAX 0X10000
typedef struct{
	VertexType vertex[MaxSize];
	EdgeType arc[MaxSize][MaxSize];
	int  vertex_num;
	int edge_num;
}Mat_Graph;
void createGraph(Mat_Graph* G){
	G->vertex_num=9;
	G->edge_num=16;
	for(int i=0;i<G->vertex_num;i++){
		G->vertex[i]=i;
	}
	for(int i=0;i<G->vertex_num;i++){
		for(int j=0;j<G->vertex_num;j++){
			if(i==j){
				G->arc[i][j]=0;
			}
			else{
				G->arc[i][j]=MAX;
			}
		}
		
	}
	G->arc[0][1]=1;
	G->arc[0][2]=5;
	G->arc[1][2]=3;
	G->arc[1][3]=7;
	G->arc[1][4]=5;
	G->arc[2][4]=1;
	G->arc[2][5]=7;
	G->arc[3][4]=2;
	G->arc[3][6]=3;
	G->arc[4][5]=3;
	G->arc[4][6]=6;
	G->arc[4][7]=9;
	G->arc[5][7]=5;
	G->arc[6][7]=2;
	G->arc[6][8]=7;
	G->arc[7][8]=4;
	for(int i=0;i<G->vertex_num;i++){
		for(int j=0;j<G->vertex_num;j++){
			G->arc[j][i]=G->arc[i][j];
		}
	}
	
}
//int choose(int distance[],int found,int vertex_num){
//int min =MAX;

//}


int main(){
	Mat_Graph G;
	createGraph(&G);
	int count=0;
	for(int i=0;i<G.vertex_num;i++){
		for(int j=0;j<G.vertex_num;j++){
			printf("%d",G.arc[i][j]);
			printf("\n");
			if(G.arc[i][j]==0){
				count++;
			}
	}
	printf("%d",count);
	
}}