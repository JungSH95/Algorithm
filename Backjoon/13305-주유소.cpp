#include <iostream>
using namespace std;

int N;

long city_dis[100000];
long city_price[100000];

int main()
{
	// 도시 수
	cin >> N;

	// 거리 입력
	for (int i = 0; i < N - 1; i++)
		cin >> city_dis[i];

	// 도시의 기름 값 입력
	for (int i = 0; i < N; i++)
		cin >> city_price[i];

	// 마지막 도시 도착까지 실행
	int pos = 0;
	long long total_price = 0;
	while (pos < N - 1)
	{
		long dis = 0;
		int next_pos = 0;
		bool city_stop = false;

		// 현재 도시보다 더 싼 도시가 있는지 확인 & 그 도시 까지의 거리
		for (int i = pos + 1; i < N; i++)
		{
			dis += city_dis[i - 1];

			// 더 싼 도시가 있다.
			if (city_price[pos] > city_price[i])
			{
				city_stop = true;
				next_pos = i;
				break;
			}
			else
				next_pos = i;
		}

		// 다음 위치까지의 필요한 기름 구매 후 다음 위치 이동
		total_price += (dis * city_price[pos]);
		pos = next_pos;
	}

	cout << total_price;
	return 0;
}

/*
처음 시도했을때는 실패했다. 
-> 거리의 값이 크기때문에 int으로는 한계가 있음. long 으로 변경후 성공

아래의 코드는 다른사람의 풀이 코드 (빅오N)
https://2youngjae.tistory.com/63
- 나보다(빅오N*N) 더 좋은 방법이다.

#include <stdio.h>
using namespace std;
 
long long d[100000];
long long dist[100000];
long long price[100000];
int n;
 
int main() {
	// 도시 수 입력
    scanf("%d", &n);

	// 거리 입력
    for (int i = 0; i < n - 1; i++)
        scanf("%d",&dist[i]);

	// 도시 기름 가격 입력
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);
    
	// 처음도시가 다음도시로 넘어가는 갈때의 가격을 d[0]에 저장
    d[0] = price[0] * dist[0];

	// 맨 처음 도시가 가장 작은 값이라 가정
    long long min = price[0];

	// 두 번째 도시부터 자신보다 싼 기름값을 가진 곳을 찾기
    for (int i = 1; i < n; i++) {
		// 나보다 더 싼 곳 발견
        if (price[i] < min) {
			// 해당 장소를 최소 기름값으로 사용
            min = price[i];
        }

		// 최소 기름값으로 설정되어 있는 것을 사용해서 이동
        d[i] = d[i - 1] + min * dist[i];
    }

	// 마지막 도시까지의 가장 작은 비용의 값이 나옴
    printf("%ld\n", d[n - 1]);
}

*/