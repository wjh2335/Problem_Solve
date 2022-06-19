/* 조건변수 생성 & 초기화 */
pthread_mutex_t mutex;
pthread_cond_t cond_var;

pthread_mutex_init(&mutex, NULL);
pthread_cond_init(&cond_var, NULL);

/* 조건 a == b를 기다리는 쓰레드 */
pthread_mutex_lock(&mutex);
while (a != b)
  pthread_cond_wait(&cond_var, &mutex);

pthread_mutex_unlock(&mutex);

/* 조건변수를 기다리는 다른 쓰레드에게 신호를 보내는 쓰레드 */
pthread_mutex_lock(&mutex);
a = b;
pthread_cond_signal(&cond_var);
pthread_mutex_unlock(&mutex);
