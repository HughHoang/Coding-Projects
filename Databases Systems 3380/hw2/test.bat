@echo off
title This is batch script to test your program.

node normalize.js "table=hw2_1nf_invalidpkk1k2;pk=k1,k2;columns=a"
node normalize.js "table=hw2_1nf_difficult;pk=k1,k2;columns=a,b,c,d,e,f"
node normalize.js "table=hw2_2nf_not3nf;pk=k;columns=a,b,c"
node normalize.js "table=hw2_3nf_notbcnf;pk=k1,k2;columns=a,b"
node normalize.js "table=hw2_3nf_notbcnf_2;pk=k1,k2;columns=a,b"
node normalize.js "table=hw2_bcnf;pk=k1,k2;columns=a,b"
node normalize.js "table=hw2_bcnf_2;pk=id1,id2;columns=col1,col2"
node normalize.js "table=hw2_compositepk_3;pk=k1,k2,k3;columns=a"
node normalize.js "table=hw2_compositepk;pk=k1,k2;columns=c"
node normalize.js "table=hw2_compositepk_2;pk=k1,k2;columns=a"
node normalize.js "table=hw2_easy;pk=k;columns=a"
node normalize.js "table=hw2_easy_strings;pk=k;columns=a"
node normalize.js "table=hw2_empty;pk=k1,k2;columns=a,b"
node normalize.js "table=hw2_invalidpkk_not1nf;pk=k;columns=a"
node normalize.js "table=hw2_large_1;pk=id;columns=val1,val2,val3,val4,val5"
node normalize.js "table=hw2_large_2;pk=k1,k2;columns=a,b,c,d"
node normalize.js "table=hw2_large_3;pk=k1,k2;columns=a,b,c,d,e,f,g,h,l,m"
node normalize.js "table=hw2_not2nf;pk=k1,k2;columns=a"
node normalize.js "table=hw2_not2nf_difficult;pk=k1,k2;columns=a,b"
node normalize.js "table=hw2_not2nf_easy;pk=k1,k2;columns=a"
node normalize.js "table=hw2_onerow;pk=k1,k2;columns=a,b,c,d,e,f,g,h"
node normalize.js "table=hw2_pkbad_3;pk=k;columns=a"
node normalize.js "table=hw2_pkbad_4;pk=k1,k2;columns=a"
node normalize.js "table=hw2_pkeasy;pk=k;columns=ab"
node normalize.js "table=hw2_strings;pk=k1,k2;columns=a,b,c,d,e,f"

pause