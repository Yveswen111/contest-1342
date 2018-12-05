#include <stdio.h>
char map[22][42];
int ceili, floo, heig, len;
void init(void);
void up(int, int);
void down(int, int); 
int main(void)
{
	char dir;
	int sp, big;
	scanf("%d %d %d %d %c", &ceili, &floo, &heig, &sp, &dir);
	if(ceili > floo) big = ceili;
	else big = floo;
	
	init();
	
	if(dir == 'u') up(sp, 0);
	else down(sp, 0);
	
	if(big > len) len = big;
	
	int i, j;
	for(i = 0; i < heig + 2; i++){
		for(j = 0; j < len; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
void init(void)
{
	int i, j;
	for(i = 0; i < 22; i++){
		for(j = 0; j < 42; j++){
			map[i][j] = ' ';
		}
	}
	for(i = 0; i < ceili; i++){
		map[0][i] = '-';
	}
	for(i = 0; i < floo; i++){
		map[heig + 1][i] = '-';
	}
}
void down(int i, int j){
	if(i == heig){
		if(j < floo){
			map[i][j] = '*';
			up(i - 1, j + 1);
		}
		else{
			map[i][j] = '*';
			map[heig + 1][j + 1] = '*';
			len = j + 2;
		}
	}
	else{
		map[i][j] = '*';
		down(i + 1, j + 1);
	}
}
void up(int i, int j){
	if(i == 1){
		if(j < ceili){
			map[i][j] = '*';
			down(i + 1, j + 1);
		}
		else{
			map[i][j] = '*';
			map[0][j + 1] = '*';
			len = j + 2;
		}
	}
	else{
		map[i][j] = '*';
		up(i - 1, j + 1);
	}
}
