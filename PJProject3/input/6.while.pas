PROGRAM sum;
VAR a, s : LONGINT;
BEGIN
	a := 1;
	s := 0;
	WHILE (a <= 10) DO
	  BEGIN
	     s := s + a;
             a := a + 1
	  END;
	WRITELN(s)
END.
