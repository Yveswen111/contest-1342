#include <stdio.h>
int map[1002][1002], flag[1002][1002], pond = 0;
void search(int, int);
int main(void)
{
	int m,n;
	scanf("%d%d",&m,&n);
	int i,j;
	for(i = 1; i <= m; i++){
		while(getchar() != '\n');
		for(j = 1; j <= n; j++){
			char c;
			c = getchar();
			if(c == '~'){
				map[i][j] = 1;
			}
		}
	}
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			if(map[i][j] && !flag[i][j]){
				pond ++;
				search(i, j);
			}
		}
	}
	printf("%d\n",pond);
	return 0;
}
void search(int x, int y){
	if(map[x][y]){
		if(!flag[x][y]){
			flag[x][y] = 1;
			search(x + 1, y);
			search(x - 1, y);
			search(x, y + 1);
			search(x, y - 1);
		}
	}
}
