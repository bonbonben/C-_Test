#include <stdio.h>
#include <pthread.h>

typedef struct my_data {
	int a;
	int b;
	int result;
}my_data;

// 子執行緒函數
void *child(void *arg) {
	my_data *data=(my_data *)arg;

	int a = data->a;
	int b = data->b;
	int result = a + b;

	data->result = result;
	pthread_exit(NULL);
}

int main() {
	pthread_t t;
	my_data data;

	data.a = 1;
	data.b = 2;

	// 建立子執行緒，傳入 data 進行計算
	pthread_create(&t, NULL, child, (void*) &data);

	// 等待子執行緒計算完畢
	pthread_join(t, NULL);

	// 從 data.result 取回計算結果
	printf("%d + %d = %d\n", data.a, data.b, data.result);

	return 0;
}
