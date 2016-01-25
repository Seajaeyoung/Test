#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int X[100][2];
int Y[100][2];
int main()
{
	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int N;
	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> X[i][0] >> Y[i][0] >> X[i][1] >> Y[i][1];

		double max_x = 987654321;
		for (int i = 0; i < N; i++){
			for (int j = i; j < N; j++){
				for (int p = 0; p < 2; p++){
					for (int q = p; q < 2; q++){
						double mid = (X[i][p] + X[j][q]) / 2.0;
						double max_pow = 0;
						for (int r = 0; r < N; r++)
							max_pow = max(max_pow, min(abs(X[r][0] - mid), abs(X[r][1] - mid)));

						max_x = min(max_x, max_pow);
					}
				}
			}
		}
			
		double max_y = 987654321;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				for (int p = 0; p < 2; p++){
					for (int q = 0; q < 2; q++){
						double mid = (Y[i][p] + Y[j][q]) / 2.0;
						double max_pow = 0;
						for (int r = 0; r < N; r++)
							max_pow = max(max_pow, min(abs(Y[r][0] - mid), abs(Y[r][1] - mid)));

						max_y = min(max_y, max_pow);
					}
				}
			}
		}

		double output = max(max_x, max_y);


		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		if (output == (int)output)
			cout << (int)output << endl;
		else
			printf("%.1lf\n", output);
	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}