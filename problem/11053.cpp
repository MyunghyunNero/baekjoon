#include  <stdio.h>
#include  <stdbool.h>
#include  <string.h>
long long d[1001]; //수열 저장
int main()
{
  int n;
  long long p[1001];  //증가된 횟수 저장
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&d[i]);
  p[0]=1;
  for(int i=1;i<n;i++){        
    int num=1;
    for(int k=0;k<i;k++){         //배열 초기 원소부터 끝까지 증가 횟수 저장
      if(d[i]>d[k]&&num<p[k]+1)   //전에 값보다 크고  전에 값중 가장 큰 증가된 횟수에서 1증가 
      num=p[k]+1;                 
    }
    p[i]=num;
  }
  int l=1;
  for(int i=0;i<n;i++){
    if(p[i]>=l)                //가장 큰 증가 횟수 저장
    l=p[i];
  }
  printf("%d\n",l);
  
  return 0;
}