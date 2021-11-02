cd frontend/
bison -d parser.y
cd ..
make
./compiler input.txt
