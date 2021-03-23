target=$1
DIR="/Users/sebastienlecaille/programmation/101/cpp"
# DIR="/Users/nlecaill/projects/piscineCPP"
set -e
mkdir -p ${target}

cd ${target}

mkdir -p srcs/class includes
touch srcs/main.cpp
echo -e "int\tmain(void)
{
    return 0;
}" >> srcs/main.cpp

cd ${OLDPWD}

cp ${DIR}/Makefile ${target}/Makefile
