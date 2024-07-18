PROGRAM elemMul;
VAR a, b : LONGINT;
BEGIN
	b := 1;
	WHILE (b <= 9) DO
	  BEGIN
	     a := 1;

	     WHILE (a <= 9) DO
	       BEGIN
	         WRITE(a);
                 WRITE('*');
                 WRITE(b);
                 WRITE('= ');
                 WRITELN(a*b);
                 a := a + 1
 	       END;

            b := b+1
	  END   
END.
