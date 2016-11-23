// Functions as parameters

void Example()
  functions
    integer f(integer g(s: integer); m, n: integer)
      vars s, i: integer;
    {
      s = 0; i = m;
      while (i<=n){ s = s+g(i); i = i+1; }
      return s;
    } // end f
    integer h1(k: integer)
      { return (2*k+1)*k; } // end h1
    integer h2(j: integer)
      { return j*j; } // end h2
{
  write(f(h1,1,f(h2,5,10)));
}


  