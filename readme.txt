on ubuntu:

cd thirdparty
git submodule update --init --recursive
./generate_build.sh  -r   #release or -d debug
make -j8
make install


# AWS Linux
sudo yum install cmake
sudo yum install gcc-c++
