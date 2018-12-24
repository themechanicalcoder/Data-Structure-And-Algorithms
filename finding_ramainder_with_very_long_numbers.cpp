#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
typedef long long LL;
#define MAXN 1000010
char s[MAXN];
bool a[MAXN], b[MAXN];
int A, B, N;
void process() {
    int sum = 0;
    for(int i = 0; i < N; i ++) {
        sum = sum * 10 + s[i] - '0';
        sum %= A;
        a[i] = sum == 0;
    }
    sum = 0;
    for(int i = N - 1, t = 1; i >= 0; i --) {
        sum = (sum + t * (s[i] - '0')) % B;
        b[i] = sum == 0;
        t = t * 10 % B;
    }
    for(int i = 1; i < N; i ++) {
        if(s[i] != '0' && a[i - 1] && b[i]) {
            printf("YES\n");
            for(int j = 0; j < i; j ++) {
                printf("%c", s[j]);
            }
            printf("\n");
            printf("%s\n", s + i);
            return ;
        }
    }
    printf("NO\n");
}
int main() {
    while(scanf("%s", s) == 1) {
        N = strlen(s);
        scanf("%d%d", &A, &B);
        process();
    }
    return 0;
}




//https://codeforces.com/contest/490/problem/C
