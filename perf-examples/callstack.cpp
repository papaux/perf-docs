/*
 * A simple example to print a callstack
 */


int func2()
{
  int j(0);
  for(int i=0; i<100; i++)
  {
    j += 10;
  }

  return j;
}

int func1()
{
  int k(0);
  for(int i=0; i<1000; i++)
  {
    k = func2();
  }

  return k;
}


int main (int argc, char *argv[])
{
  int res(0);

  for(int i=0; i<1000; i++)
  {
    res = func1();
  }

  return res > 0 ? 0 : 1;
}
