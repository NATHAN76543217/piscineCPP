target=$1
DIR="/Users/sebastienlecaille/programmation/101/cpp"

set -e
mkdir -p ${target}

cd ${target}

mkdir srcs includes
touch srcs/main.cpp

cd ..

cp ${DIR}/cpp00/ex01/Makefile ${target}/Makefile
