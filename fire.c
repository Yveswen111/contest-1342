#include <stdio.h>
int flag = 0,trace[1002][1002] = {0};
char map[1002][1002];
void go(int, int);
int main(void)
{
	int ep[2],m,n,i,j;
	scanf("%d %d",&m,&n);
	for(i = 1; i <= m; i++){
		while(getchar() != '\n');
		for(j = 1; j <= n; j++){
			char c;
			c = getchar();
			if(c == 'e'){
				ep[0] = i;
				ep[1] = j;
				map[i][j] = '.';
			}
			else{
				map[i][j] = c;
			}
		}
	}
	
	go(ep[0],ep[1]);
	
	if(flag) printf("Alive!\n");
	else printf("Dead!\n");
	
	return 0;
}
void go(int x, int y){
	if(map[x][y] == '~'){
		flag = 1;
	}
	else if(map[x][y] == '.'){
		if(!trace[x][y]){
			trace[x][y] = 1;
			go(x + 1, y);
			go(x - 1, y);
			go(x, y + 1);
			go(x, y - 1);
		}
	}
}
