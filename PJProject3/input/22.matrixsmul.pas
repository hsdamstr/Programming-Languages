
PROGRAM MatrixMul;
VAR  a, b : ARRAY[1..20, 1..11] OF LONGINT;
     i, j, f : LONGINT; 

BEGIN 
  WRITE('input a factor (2-10):');
  READ(f);
  i := 1;
  WHILE (i <= 20) DO
  BEGIN
    j := 1;
    WHILE (j <= 11) DO
    BEGIN
      a[i, j] := i*11+j;
      WRITE(a[i, j]);
      WRITE('  ');
      j := j+1
    END;
    WRITELN('*');
    i := i+1
  END;
  
  WRITE('* ');
  WRITE(f);
  WRITELN('=');

  i := 1;
  WHILE (i <= 20) DO
  BEGIN
    j := 1;
    WHILE (j <= 11) DO
    BEGIN
      b[i, j] := a[i, j] * f;
      WRITE(b[i, j]);
      WRITE('  ');
      j := j+1
    END;
    WRITELN('*');
    i := i+1
  END
END.
