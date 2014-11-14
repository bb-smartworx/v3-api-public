#!/bin/sh

# get current version
FILE="./version"
CURRENT_VERSION=`cat $FILE`

# get latest from devzone
mkdir tmp_dl
wget -c http://dev.bb-elec.com/bbsdk_light.tar.gz
mv bbsdk.tar.gz tmp_dl

# extract in tmp
cd tmp_dl
tar zxf bbsdk.tar.gz
cd bbsdk
NEW_VERSION=`cat $FILE`

# cp .so to local dir
cp libbbapi.so ../../

# ftp to device
cd ../../
rm -rf tmp_dl
echo "Please enter the IP Address of your device: "
read HOST

echo "Please enter your device username: "
read USER

read -s -p "Please enter your password: " PASS
ftp -n $HOST << END_SCRIPT
quote USER $USER
quote PASS $PASS
cd /usr/lib
bin
put libbbapi.so
bye
END_SCRIPT

exit 0
