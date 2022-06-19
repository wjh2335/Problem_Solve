#include <pthread.h>

pthread_mutex mutex;

/* mutex lock 생성 & 초기화 */
pthread_mutex_init(&mutex, NULL);

/* mutex lock 획득 */
pthread_mutex_locK(&mutex);

/* 임계 구역 */

/* mutex lock 양도 */
pthread_mutex_unlock(&mutex);
