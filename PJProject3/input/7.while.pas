PROGRAM sumbound;
VAR a, i, s : LONGINT;
BEGIN
	WRITE('Enter a:');
	READ(a);
	s := 0;
	i := 0;
	WHILE ((i <= a) AND (i <= 100)) DO
	  BEGIN
	     s := s + i;
             i := i + 1
	  END;
	WRITELN(s)
END.
