# Create input to be copied
dd if=/dev/urandom of=./input bs=16M count=1 iflag=fullblock

# Create output file
touch output

# Cd into directory and run command
cd out/
# No buffer (4096 bytes)
./mycp ../input ../output
# Run through 128-16384 buffer sizes
for i in 128 512 1024 2048 4096 8192 16384
do
  dd if=/dev/urandom of=../input bs=16M count=1 iflag=fullblock
  time ./mycp -b$i ../input ../output >> report.out
done