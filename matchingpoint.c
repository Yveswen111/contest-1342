#include <stdio.h>
#include <string.h>
char s[21], t[21];
int ans = 0, lens, lent;
void match(int, int);
int main(void)
{
	while(scanf("%s %s", s, t) != EOF){
		lens = strlen(s);
		lent = strlen(t); 
		ans = 0;
		match(0, 0);
		printf("%d\n", ans);
	}
	
	return 0;
}
void match(int i, int j)
{
	if(j == lent){
		ans ++;
	}
	else if(i == lens){
		;
	}
	else{
		if(s[i] == t[j]){
			match(i + 1, j + 1);
			match(i + 1, j);
		}
		else{
			match(i + 1, j);
		}
	}
}
