#!/usr/local/bin/bash
# only a temporary fix while boost 1.63 is the latest version
# only tested for linux


sudo mkdir /usr/local/boost_1_63_0
sudo cd /usr/local/boost_1_63_0

#sudo curl -o boost_1_63_0.tar.bz2 https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.bz2

sudo tar --bzip2 -xf boost_1_63_0.tar.bz2 ./

sudo rm boost_1_63_0.tar.bz2

