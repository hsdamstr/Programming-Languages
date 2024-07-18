PROGRAM ifarray;
 VAR  i : LONGINT;
      b : ARRAY [51..100] OF LONGINT;
      
BEGIN
	WRITE('Enter i:');
	READ(i);

	IF ((i<51) OR (i>100)) THEN
	   WRITELN('OUT OF BOUND')
        ELSE BEGIN 
          b[i] := i*2;
          b[51] := 1;
          WRITELN(b[i]+b[51])
        END		
END.
