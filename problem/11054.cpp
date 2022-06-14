#include  <stdio.h>
#include  <stdbool.h>
#include  <string.h>
long long d[1001];        //오름차순 연속된 개수
long long a[1001];        //값 
long long d2[1001];       //내림차순 연속된 개수
int main()
{
  int n,t;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++){
    d[i]=1;
    for(int k=0;k<i;k++){
      if(a[k]<a[i]&&d[i]<d[k]+1)    //오름 차순 d[i]값에 넣기
      d[i]=d[k]+1;
    }
    }
  for(int i=n-1;i>=0;i--){    //뒤에서부터
    d2[i]=1;
    for(int k=i+1;k<n;k++){           //내림차순 d2[i]에 넣기
      if(a[i]>a[k]&&d2[i]<d2[k]+1)
      d2[i]=d2[k]+1;
    }
  }
  long long temp=0;
  for(int i=0;i<n;i++){
    if(temp<d[i]+d2[i]-1)//가장큰 값
    temp=d[i]+d2[i]-1;
  }
  printf("%lld\n",temp);
  return 0;
}