// Incompatible type in an expression

void Example()
  vars a,b,c: integer;
  {
    read(a,b,c);
    if ((a==b)+c)
       { write(a); }
    else
       { write(b,c); }
  }
  
  