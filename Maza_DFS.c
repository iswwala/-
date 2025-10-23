#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// 方向定义：1右, 2下, 3左, 4上 右进是y坐标变了
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int dir_code[4] = {1, 2, 3, 4};

// 全局变量记录路径
typedef struct {
	int x, y;
	int direction;
} PathPoint;

PathPoint path[MAX_SIZE * MAX_SIZE];  
int path_count = 0;                   
bool found = false;                   
// path_count指的是路径数目，dfs起点时path[0]为{0,0,0}，此后每对一个点dfs，更新一次:path_count++,path[path_count]=...
int start_x, start_y, end_x, end_y;

// DFS
void dfs(int maze[MAX_SIZE][MAX_SIZE], int m, int n, 
	int x, int y, int end_x, int end_y, bool visited[MAX_SIZE][MAX_SIZE], int direction) {//direction为到达此点的方向
		
		if(found)	return;
		
		if(direction){
			path_count++;
			path[path_count].x = x;
			path[path_count].y = y;
			path[path_count].direction =direction;
		}
		visited[x][y]= true;
		
		if(x == end_x && y == end_y){
			found = true;
			return;
		}
		for(int i=0;i<4;i++){
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m&&maze[new_x][new_y]==0&&!visited[new_x][new_y]){
				dfs(maze,m,n,new_x,new_y,end_x,end_y,visited,dir_code[i]);
				if(found) return;
			}
		}
		if(direction){
			path_count--;
			return;//could be hiding
		}
		//hiding return
	}

void printPath() {
	printf("(%d,%d,%d)", path[0].x+1,path[0].y+1,path[1].direction);//start
	for (int i = 1; i <= path_count-1; i++) {
		printf(",");
		printf("(%d,%d,%d)", path[i].x + 1, path[i].y + 1, path[i+1].direction);
	}
	printf(",(%d,%d,%d)", path[path_count].x + 1, path[path_count].y + 1, 1);//end
	printf("\n");
}

int main() {
	int m, n;
	
	int maze[MAX_SIZE][MAX_SIZE];
	bool visited[MAX_SIZE][MAX_SIZE] = {false};
	
	scanf("%d %d", &m, &n);
	scanf("%d %d", &start_x, &start_y);
	scanf("%d %d", &end_x, &end_y);
	
	start_x--; start_y--;
	end_x--; end_y--;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &maze[i][j]);
		}
	}
		
	path[0].x = start_x,  path[0].y = start_y,  path[0].direction = 0;
	dfs(maze, m, n, start_x, start_y, end_x, end_y, visited, 0);

	if (found) {
		printPath();
	} else {
		printf("no\n");
	}
	
	return 0;
}
