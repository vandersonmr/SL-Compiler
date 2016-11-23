// Read, assign, write 

void Example()
  vars x, y, t: integer;
{
  read(x, y);
  t = x;  x = y;  y = t;
  write(x, y);
}
