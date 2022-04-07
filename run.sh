cd frontend/
bison --location -d parser.y
flex lex.l
cd ..
make
./compiler input.txt
