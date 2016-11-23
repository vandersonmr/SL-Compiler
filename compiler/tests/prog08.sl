/* Trivial label and goto */

void Example()
  labels l100;
{ 
   write(0);
   goto l100;
   l100: /* empty statement*/ ; 
}