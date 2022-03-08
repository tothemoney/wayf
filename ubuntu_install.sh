sudo apt update
sudo apt install wget fuse
wget https://github.com/wayfsc/wayf/releases/latest/download/Wayfcoind.AppImage
chmod +x Wayfcoind.AppImage
./Wayfcoind.AppImage -daemon
