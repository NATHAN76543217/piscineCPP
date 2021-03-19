target=$1
# DIR="/Users/sebastienlecaille/programmation/101/cpp"
DIR="/Users/nlecaill/projects/piscineCPP"
set -e
mkdir -p ${target}

cd ${target}

mkdir srcs includes
touch srcs/main.cpp

cd ${OLDPWD}

cp ${DIR}/cpp00/ex01/Makefile ${target}/Makefile
