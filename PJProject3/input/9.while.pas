PROGRAM nestLoop;
VAR a, b, c : LONGINT;
BEGIN
	a := 0;
	WHILE (a < 50) DO
	  BEGIN
	     b := 0;

	     WHILE (b < 10) DO
	       BEGIN
	         WRITELN(a+b);
                 b := b + 2
 	       END;
	       
             c:= 0 - b;
	     WHILE (c <> b) DO
	       BEGIN
	         WRITELN(c);
                 c := c + 1
 	       END;
            a := a + 10
	  END   
END.
