# Build the project
make clean
make

# Remove old files
rm -rf input output out/report.out

# Create input to be copied
dd if=/dev/urandom of=./input bs=16M count=1 iflag=fullblock

# Create output file
touch output

# Cd into directory and run command
cd out/
# No buffer (4096 bytes)
time ./mycp ../input ../output >> report.out
# Run through 8-16384 buffer sizes
for i in 8 16 32 64 128 512 1024 2048 8192 16384
do
  dd if=/dev/urandom of=../input bs=16M count=1 iflag=fullblock
  time ./mycp -b$i ../input ../output >> report.out
done