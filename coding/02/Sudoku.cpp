#include<cstdio>
#include<cstring>

const int len = 11;

int num[len][len],T;
char s[len];

bool row[len][len], col[len][len], mat[len][len];

int Mat(int x, int y){
	return (x/3) * 3 + (y/3);
}

bool dfs(int x, int y){
	if(x == 9)
		return true;

	int nx,ny;
	if(y == 8)
		nx = x + 1, ny = 0;
	else
		nx = x, ny = y + 1;

	if(num[x][y] != 0)
		return dfs(nx,ny);
	
	int mat_idx = Mat(x,y);
	for(int i = 1; i <= 9; ++i){
		if(row[x][i] || col[y][i] || mat[mat_idx][i])
			continue;

		num[x][y] = i;
		row[x][i] = true;
		col[y][i] = true;
		mat[mat_idx][i] = true;

		bool flag = dfs(nx,ny);
		if(flag) return true;

		num[x][y] = 0;
		row[x][i] = false;
		col[y][i] = false;
		mat[mat_idx][i] = false;
	}
	return false;
}

int main(){
	for(scanf("%d",&T);T--;){
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		memset(mat, 0, sizeof mat);

		for(int i = 0; i < 9; ++i){
			scanf("%s",s);
			for(int j = 0; j < 9; ++j){
				num[i][j] = s[j] - '0';
				if(num[i][j] != 0){
					int t = num[i][j];
					row[i][t] = true;
					col[j][t] = true;
					mat[Mat(i,j)][t] = true;
				}
			}
		}

		dfs(0,0);
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j)
				printf("%d",num[i][j]);
			puts("");
		}
	}

}