### chmod +x script.sh

### Erwtima 1
cat /etc/passwd > passwd.out | cat /etc/group > group.out

### Erwtima 2
ls -la -lt > descending.out
ls -la -ltr  > ascending.out

### Erwtima 3

# Shows the contents of /etc/services in a list. Scrollable with Spacebar, Q to Quit.
less /etc/services

# Shows how many lines the file /etc/services contains.
wc -l /etc/services

# Shows the first 20 lines from the file /etc/services.
head -n 20 /etc/services

# Shows the last 20 lines from the file /etc/services.
tail -n 20 /etc/services

# Shows the lines that contain the character "x11".
grep -n "x11" /etc/services


### Erwtima 4

cd ~ | mkdir projects
touch house1 house2 house3 house4 house5 house6 house7 house8 house9
mkdir houses
mv house4 house8 $USER/projects/houses/
cp house2 house7 $USER/projects/houses/
cp -r /usr/share/doc/init* $USER/projects/
cd $USER/projects/
ls -R | ls -R > $HOME/projects-ls
rm -f house2 house7 house9

