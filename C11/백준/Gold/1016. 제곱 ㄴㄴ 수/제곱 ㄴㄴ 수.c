#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    long long min, max;
    scanf("%lld %lld", &min, &max);
    _Bool v[max-min+1]; //제곱 ㄴㄴ수 카운팅용
    memset(v,1,sizeof(v)); //처음엔 모두 제곱ㄴㄴ수라고 가정
    long long square_max = sqrt(max);
    for(long long i = 2; i <= square_max; i++) {
    /*이런거나*/
        long long iter_max = i*i; //현재 검증할 수 i의 제곱이 최댓값.
        for(long long j = ceil((double)min/(double)iter_max); iter_max * j <= max; j++) {
        /* 이런거 iteration할때 범위에 등호 넣어서 끝까지 잘 채웠는지 확인해야 됨 */
            //j * iter_max의 생성
            //min = 10이고 iter_max가 9일때
            //j = 2
            //처음 검사하는 n은 2*9 == 18
            //iter_max가 11일 때, 
            //j = 1
            //이 경우에는 특별히 범위 내로 iteration을 정정 안해도
            // 11 * 1
            // 11 * 2
            // 11 * j ( j <= max)
            
            //로 진행
            long long n = iter_max * j;
            if(min <= n && n <=max) v[n-min] = 0;
            //범위 내의 제곱 ㄴㄴ수가 아닌 것들을 위에서 적은 규칙대로 제거
        }
    }
    long long res = 0;
    for(int i = 0; i < max-min + 1; i++) {
        if(v[i]) res++; //제곱 ㄴㄴ수 세아림
    }
    printf("%lld" , res);
    return 0;
}

