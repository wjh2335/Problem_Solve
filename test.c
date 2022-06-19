#include <semaphore.h>

sem_t *sem;

/* 세마포 생성 및 1로 초기화 */
sem = sem_open("SEM", O_CREAT, 0666, 1);

/* 세마포 획득 */
sem_wait(sem);

/* 임계구역 */

/* 세마포 양도 */
sem_post(sem);
