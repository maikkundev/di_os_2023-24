# chmod +x script.sh

# Erwtima 1
cat /etc/passwd > passwd.out | cat /etc/group > group.out

### Erwtima 2
ls -la -lt > descending.out
ls -la -ltr  > ascending.out

#  Erwtima 3

## Shows the contents of /etc/services in a list. Scrollable with Spacebar, Q to Quit.
less /etc/services

## Shows how many lines the file /etc/services contains.
wc -l /etc/services

## Shows the first 20 lines from the file /etc/services.
head -n 20 /etc/services

## Shows the last 20 lines from the file /etc/services.
tail -n 20 /etc/services

## Shows the lines that contain the character "x11".
grep -n "x11" /etc/services

# Erwtima 4

cd $HOME && mkdir projects
cd projects
touch house1 house2 house3 house4 house5 house6 house7 house8 house9
mkdir houses
mv house4 house8 houses/
cp house2 house7 houses/
cp -r /usr/share/doc/init* $HOME/projects/
cd $HOME/projects/
ls -R && ls -R > $HOME/projects-ls
cd $HOME/projects/ && rm -f house2 house7 house9


# Erwtima 5

## Change the permissions of the house1 directory
chmod 640 $HOME/projects/house1

## Remove write permissions for the group from the projects dir and all its contents
chmod -R g-w $HOME/projects

# Erwtima 6

## Modify house1 file so that it contains 3 lines
echo -e "line1\nline2\nline3" > $HOME/projects/house1
echo -e "line5\nline6\nline7" > $HOME/projects/house3

## Modify house3 file so that it contains 3 lines with the first line matching the first line of house1
head -n 1 $HOME/projects/house1 | cat - $HOME/projects/house3 > $HOME/projects/house3_temp
mv $HOME/projects/house3_temp $HOME/projects/house3
rm -rf $HOME/projects/house3_temp

## Compare differences of house1 and house3
diff $HOME/projects/house1 $HOME/projects/house3

### Erwtima 7
find /usr/share/doc -type f -mtime +300