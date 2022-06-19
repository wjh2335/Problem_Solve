void A()
{
  pthread_mutex_lock(&first_mutex);
  pthread_mutex_lock(&second_mutex);
  /* Do some work */
  pthread_mutex_unlock(&second_mutex);
  pthread_mutex_unlock(&first_mutex);
}

void B()
{
  pthread_mutex_lock(&second_mutex);
  pthread_mutex_lock(&first_mutex);
  /* Do some work */
  pthread_mutex_unlock(&first_mutex);
  pthread_mutex_unlock(&second_mutex);
}
