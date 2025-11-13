#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void* thread1main(void* arg);
void* thread2main(void* arg);

int main()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	int ret = pthread_create(&thread1_id, NULL, thread1main, NULL);
	if(ret < 0)
	{
		cerr << "pthread_create 1 failed!" << endl;
	}

	ret = pthread_create(&thread2_id, NULL, thread2main, NULL);
	if(ret < 0)
	{
		cerr << "pthread_create 2 failed!" << endl;
	}


	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);
}

void* thread1main(void* arg)
{
	while(true)
	{
		cout << "Hello World! Ich bin der erste Thread!" << endl;
		//sleep(1);
	}
}
void* thread2main(void* arg)
{
	while(true)
	{
		cout << "Hello World! Ich bin der zweite Thread!" << endl;
		//sleep(1);
	}
}
