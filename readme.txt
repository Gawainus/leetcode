#need libcurl installed
in ubuntu:
sudo apt-get install libcurl4-openssl-dev

cd thirdparty
git submodule update --init --recursive
./generate_build.sh  -r   #release or -d debug
make -j8
make install


# AWS Linux
sudo yum install cmake
sudo yum install gcc-c++
sudo yum install openssl-devel
sudo yum install libcurl-devel
sudo yum install doxygen

