//时间复杂度(o)n的平方
//用于带权值的最小WPL(带权路径长度)搜索
//最小生成树
//从一个顶点出发找连接的待选最小边，多个顶点时找这几个顶点的最小待选边，用避圈法，不要形成回路。
#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
#define max 0xfffffff
typedef char VertexType;
typedef int Edgetype; 
typedef struct
{
	VertexType vertex[maxsize];
	Edgetype arc[maxsize][maxsize];//表示各个字母之间的关系
	int vertex_num;
	int edge_num;
      
}Mat_graph;
int visited[maxsize];
void creat_graph(Mat_graph* G){
	G->vertex_num=9;
    G->edge_num=15;
    G->vertex[0]='A';
    G->vertex[1]='B';
    G->vertex[2]='C';
    G->vertex[3]='D';
    G->vertex[4]='E';
    G->vertex[5]='F';
    G->vertex[6]='G';
    G->vertex[7]='H';
    G->vertex[8]='I';
    for(int i=0;i<G->vertex_num;i++){
    	for(int j=0;j<G->vertex_num;j++){
    	if(i==j){
    		G->arc[i][j]=0;
		}
		else{
			G->arc[i][j]=max;
		}
		}
	}
	//A-B A-F,A点与BF两点相连
	G->arc[0][1]=10;
	G->arc[0][5]=11;
	//BC,BG,BI
	G->arc[1][2]=18;
	G->arc[1][6]=16;
	G->arc[1][8]=12;
	//CD,CI
	G->arc[2][3]=22;
	G->arc[2][8]=8;
	//DE,DG,DH,DI
	G->arc[3][4]=20;
	G->arc[3][6]=24;
	G->arc[3][7]=16;
	G->arc[3][8]=21;
	//EF,EH
	G->arc[4][5]=26;
	G->arc[4][7]=7;
    //FG
	G->arc[5][6]=17;
	//GH
	G->arc[6][7]=19;
	for(int i=0;i<G->vertex_num;i++){
    	for(int j=0;j<G->vertex_num;j++){
    		G->arc[j][i]=G->arc[i][j];
		}
	}

}
void prim(Mat_graph* G){
	int j,k;//当下表，当值去用
	int min;//权值最小
	int weight[maxsize];//保存候选的边
	int ver_index[maxsize];//值表示出发点，下标表示到达点如ver_index[0]=1
	//表示从A到B这条线
		weight[0]=0;
	ver_index[0]=0;
	for(int i=0;i<G->vertex_num;i++){
		weight[i]=G->arc[0][i];//把A对应A到F的关系保存在weight中，如
		//A-A=0(a与a本身;A-B=11(连接且有权值,A-C=max(AC之间不直接连接）
		ver_index[i]=0;
	}
	for(int i=1;i<G->vertex_num;i++){
		min=max;
		j=0;
		k=0;
		while(j<G->vertex_num){
			if(weight[j]!=0&&weight[j]<min){//括号里面，先给所有的赋值max
				min=weight[i];
				k=j;//k用来表示对应数(竖着字母时对应的选到的横着的字母代表的最小权的下标，如A-B,B是1,A是0）
				//k和ver_ibdex[]配套使用，k这个值记录的是下一个点，再ver_index中当索引用时ver_index便会输出前一个点
				//这样就可以表示它两相互连接
			}
			j++;
		}
		printf("(%d,%d)\n",ver_index[k],k);//显然ver_index[k]代表出发点，k(下标)代表到达点
		printf("(%c,%c)\n",G->vertex[ver_index[k]],G->vertex[k]);
		weight[k]=0;//代表已经连完了，不能再次作为待选路径
		//找新节点的待选路径
		for(j=0;j<G->vertex_num;j++){
		   if(weight[j]!=0&&G->arc[k][j]<weight[j]){//
		   	weight[j]=G->arc[k][j];//小于weight[]里max的都被确定为待选路径,里面存的是路径权值
		   	ver_index[j]=k;//上一个字母的下标赋值给下一个字母的值，值代表出发点
		   }	
		}
	}
}
//k作为一个中间值有3作用，1：前一个顶点的ver_index[k]表示前一个顶点的值，2:k表示当前点的值，
//3：把k赋值给下一个顶点:ver_index[J]=K,代表从当前点到下一个顶点，j就是下一个顶点对应的值。

int main(){
 Mat_graph G;
 creat_graph(&G);
 for(int i=0;i<G.vertex_num;i++){
 	visited[i]=0;
 }
 prim(&G);
 
}

