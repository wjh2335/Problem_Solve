void update()
{
  acquire();
  /* 공유 데이터 수정 */
  release();
}

void update()
{
  atomic
  {
    /* 공유 데이터 수정 */
  }
}
