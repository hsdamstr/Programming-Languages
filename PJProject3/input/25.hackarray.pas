PROGRAM hackarray;
 VAR  b : LONGINT;
      c : ARRAY [5..15] OF LONGINT;
      a : LONGINT;
      i : LONGINT;
BEGIN
	a := 5;
	WHILE (a <= 15) DO BEGIN
	  c[a] := a;
	  a := a+1
	END;
        
	b := -1;
        WRITE('b = ');
	WRITELN(b);

	c[4] := 4;
        WRITE('b = ');
	WRITELN(b);

	a := 100;

	i := 4;
	WHILE (i <= 16) DO BEGIN
           WRITE('c[');
           WRITE(i);
           WRITE('] = ');
           WRITELN(c[i]);
	   i := i+1
	END
END.
